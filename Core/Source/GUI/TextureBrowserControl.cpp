/*
 Copyright (C) 2010-2012 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "TextureBrowserControl.h"
#include "Controller/Editor.h"
#include "Model/Map/Map.h"
#include "Model/Selection.h"
#include "Utilities/Utils.h"
#include "Utilities/VecMath.h"
#include "Gwen/Skin.h"
#include "Gwen/Controls/ScrollControl.h"
#include "Gwen/Utility.h"
#include <vector>

namespace TrenchBroom {
    namespace Gui {
        void TextureBrowserPanel::textureManagerChanged(Model::Assets::TextureManager& textureManager) {
            reloadTextures();
        }

        void TextureBrowserPanel::reloadTextures() {
            m_layout.clear();
            if (m_group) {
                const vector<Model::Assets::TextureCollection*>& collections = m_editor.textureManager().collections();
                for (unsigned int i = 0; i < collections.size(); i++) {
                    Model::Assets::TextureCollection* collection = collections[i];
                    if (m_group)
                        m_layout.addGroup(collection, m_font->size + 2);
                    
                    std::vector<Model::Assets::Texture*> textures = collection->textures(m_sortCriterion);
                    for (unsigned int j = 0; j < textures.size(); j++) {
                        Model::Assets::Texture* texture = textures[j];
                        if ((!m_hideUnused || texture->usageCount > 0) && (m_filterText.empty() || containsString(texture->name, m_filterText, false))) {
                            Gwen::Point size = GetSkin()->GetRender()->MeasureText(m_font, texture->name);
                            m_layout.addItem(texture, texture->width, texture->height, static_cast<float>(size.x), m_font->size + 2);
                        }
                    }
                }
            } else {
                std::vector<Model::Assets::Texture*> textures = m_editor.textureManager().textures(m_sortCriterion);
                for (unsigned int j = 0; j < textures.size(); j++) {
                    Model::Assets::Texture* texture = textures[j];
                    if ((!m_hideUnused || texture->usageCount > 0) && (m_filterText.empty() || containsString(texture->name, m_filterText, false))) {
                        Gwen::Point size = GetSkin()->GetRender()->MeasureText(m_font, texture->name);
                        m_layout.addItem(texture, texture->width, texture->height, static_cast<float>(size.x), m_font->size + 2);
                    }
                }
            }

            const Gwen::Padding& padding = GetPadding();
            int controlHeight = static_cast<int>(m_layout.height()) + padding.top + padding.bottom;
            SetBounds(GetBounds().x, GetBounds().y, GetBounds().w, controlHeight);
        }

        void TextureBrowserPanel::renderTextureBorder(CellRow<Model::Assets::Texture*>::CellPtr cell) {
            glBegin(GL_QUADS);
            glVertex3f(cell->itemX() - 1, cell->itemY() - 1, 0);
            glVertex3f(cell->itemX() - 1, cell->itemY() + cell->itemHeight() + 1, 0);
            glVertex3f(cell->itemX() + cell->itemWidth() + 1, cell->itemY() + cell->itemHeight() + 1, 0);
            glVertex3f(cell->itemX() + cell->itemWidth() + 1, cell->itemY() - 1, 0);
            glEnd();
        }

        TextureBrowserPanel::TextureBrowserPanel(Gwen::Controls::Base* parent, Controller::Editor& editor) : Gwen::Controls::Base(parent), m_editor(editor), m_group(false) {
            m_layout.setGroupMargin(5);
            m_layout.setRowMargin(5);
            m_layout.setCellMargin(5);
            m_layout.setWidth(GetBounds().w);
            m_group = false;
            m_hideUnused = false;
            m_layout.setFixedCellWidth(64);
            m_sortCriterion = Model::Assets::TB_TS_NAME;
            SetFont(GetSkin()->GetDefaultFont());
            reloadTextures();
            
            m_editor.textureManager().textureManagerChanged += new Model::Assets::TextureManager::TextureManagerEvent::Listener<TextureBrowserPanel>(this, &TextureBrowserPanel::textureManagerChanged);
        }

        TextureBrowserPanel::~TextureBrowserPanel() {
            m_editor.textureManager().textureManagerChanged -= new Model::Assets::TextureManager::TextureManagerEvent::Listener<TextureBrowserPanel>(this, &TextureBrowserPanel::textureManagerChanged);
}
        
        void TextureBrowserPanel::SetFont(Gwen::Font* font) {
            m_font = font;
        }
        
        Gwen::Font* TextureBrowserPanel::GetFont() {
            return m_font;
        }

        void TextureBrowserPanel::SetPadding(const Gwen::Padding& padding) {
            Base::SetPadding(padding);
            m_layout.setWidth(GetBounds().w - padding.left - padding.right);
        }
        
        void TextureBrowserPanel::OnBoundsChanged( Gwen::Rect oldBounds ) {
            Base::OnBoundsChanged(oldBounds);

            const Gwen::Padding& padding = GetPadding();
            m_layout.setWidth(GetBounds().w - padding.left - padding.right);

            int controlHeight = static_cast<int>(m_layout.height()) + padding.top + padding.bottom;
            SetBounds(GetBounds().x, GetBounds().y, GetBounds().w, controlHeight);
        }

        void TextureBrowserPanel::RenderOver(Gwen::Skin::Base* skin) {
            skin->GetRender()->Flush();
            
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            
            const Gwen::Padding& padding = GetPadding();
            const Gwen::Point& offset = skin->GetRender()->GetRenderOffset();
            const Gwen::Rect& scrollerVisibleRect = ((Gwen::Controls::ScrollControl*)GetParent())->GetVisibleRect();
            const Gwen::Rect& bounds = GetRenderBounds();
            Gwen::Rect visibleRect(bounds.x, -scrollerVisibleRect.y, bounds.w, GetParent()->GetBounds().h);
            
            Model::Map& map = m_editor.map();
            Model::Selection& selection = map.selection();
            Model::Assets::TextureManager& textureManager = m_editor.textureManager();
            
            glTranslatef(offset.x, offset.y, 0);

            // paint background in black
            glColor4f(0, 0, 0, 1);
            glDisable(GL_TEXTURE_2D);
            glBegin(GL_QUADS);
            glVertex3f(0, 0, 0);
            glVertex3f(0, scrollerVisibleRect.h, 0);
            glVertex3f(scrollerVisibleRect.w, scrollerVisibleRect.h, 0);
            glVertex3f(scrollerVisibleRect.w, 0, 0);
            glEnd();
            
            glTranslatef(padding.left, padding.top, 0);
            
            for (unsigned int i = 0; i < m_layout.size(); i++) {
                CellLayout<Model::Assets::Texture*, Model::Assets::TextureCollection*>::CellGroupPtr group = m_layout[i];
                if (group->intersects(visibleRect.y, visibleRect.h)) {
                    if (m_group && group->y() + group->titleHeight() >= visibleRect.y && group->y() <= visibleRect.y + visibleRect.h) {
                        // paint background for group title
                        glDisable(GL_TEXTURE_2D);
                        glBegin(GL_QUADS);
                        glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
                        glVertex3f(0, group->y(), 0);
                        glVertex3f(0, group->y() + group->titleHeight(), 0);
                        glVertex3f(m_layout.width(), group->y() + group->titleHeight(), 0);
                        glVertex3f(m_layout.width(), group->y(), 0);
                        glEnd();
                    }
                    for (unsigned int j = 0; j < group->size(); j++) {
                        CellGroup<Model::Assets::Texture*, Model::Assets::TextureCollection*>::CellRowPtr row = (*group)[j];
                        if (row->intersects(visibleRect.y, visibleRect.h)) {
                            for (unsigned int k = 0; k < row->size(); k++) {
                                CellRow<Model::Assets::Texture*>::CellPtr cell = (*row)[k];
                                Model::Assets::Texture* texture = cell->item();
                                
                                // paint border if necessary
                                bool override = textureManager.texture(texture->name) != texture;
                                if (override) {
                                    glDisable(GL_TEXTURE_2D);
                                    glColor4f(0.5f, 0.5f, 0.5f, 1);
                                    renderTextureBorder(cell);
                                } else if (!selection.mruTextures().empty() && selection.mruTextures().back() == texture) {
                                    glDisable(GL_TEXTURE_2D);
                                    glColor4f(1, 0, 0, 0.75f);
                                    renderTextureBorder(cell);
                                } else if (texture->usageCount > 0) {
                                    glDisable(GL_TEXTURE_2D);
                                    glColor4f(1, 1, 0, 0.75f);
                                    renderTextureBorder(cell);
                                }
                                
                                // render the texture
                                glEnable(GL_TEXTURE_2D);
                                texture->activate();
                                if (override)
                                    glColor4f(1, 1, 1, 0.7f);
                                else
                                    glColor4f(1, 1, 1, 1);
                                glBegin(GL_QUADS);
                                glTexCoord2f(0, 0);
                                glVertex3f(cell->itemX(), cell->itemY(), 0);
                                glTexCoord2f(0, 1);
                                glVertex3f(cell->itemX(), cell->itemY() + cell->itemHeight(), 0);
                                glTexCoord2f(1, 1);
                                glVertex3f(cell->itemX() + cell->itemWidth(), cell->itemY() + cell->itemHeight(), 0);
                                glTexCoord2f(1, 0);
                                glVertex3f(cell->itemX() + cell->itemWidth(), cell->itemY(), 0);
                                glEnd();
                                texture->deactivate();
                            }
                        }
                    }
                }
            }
            glPopMatrix();
            
            skin->GetRender()->SetDrawColor(Gwen::Color(255, 255, 255, 255));
            for (unsigned int i = 0; i < m_layout.size(); i++) {
                CellLayout<Model::Assets::Texture*, Model::Assets::TextureCollection*>::CellGroupPtr group = m_layout[i];
                if (m_group && group->y() + group->titleHeight() >= visibleRect.y && group->y() <= visibleRect.y + visibleRect.h) {
                    Model::Assets::TextureCollection* collection = group->item();
                    std::vector<std::string> components = pathComponents(collection->name());
                    skin->GetRender()->RenderText(m_font, Gwen::Point(padding.left + 3, padding.top + group->y() + 1), components.back());
                }
                for (unsigned int j = 0; j < group->size(); j++) {
                    CellGroup<Model::Assets::Texture*, Model::Assets::TextureCollection*>::CellRowPtr row = (*group)[j];
                    for (unsigned int k = 0; k < row->size(); k++) {
                        CellRow<Model::Assets::Texture*>::CellPtr cell = (*row)[k];
                        if (cell->y() + cell->height() >= visibleRect.y && cell->y() <= visibleRect.y + visibleRect.h) {
                            Model::Assets::Texture* texture = cell->item();
                            
                            if  (m_layout.fixedCellWidth() > 0) {
                                Gwen::Font actualFont(*m_font);
                                Gwen::Point actualSize;
                                while (actualFont.size > 5 && (actualSize = skin->GetRender()->MeasureText(&actualFont, texture->name)).x > cell->width())
                                    actualFont.size -= 1.0f;
                                float actualX = cell->x() + (cell->width() - actualSize.x) / 2;
                                skin->GetRender()->RenderText(&actualFont, Gwen::Point(padding.left + actualX, padding.top + cell->titleY() + 1), texture->name);
                            } else {
                                skin->GetRender()->RenderText(m_font, Gwen::Point(padding.left + cell->titleX(), padding.top + cell->titleY() + 1), texture->name);
                            }
                        }
                    }
                }
            }
            
        }

        void TextureBrowserPanel::setHideUnused(bool hideUnused) {
            if (m_hideUnused == hideUnused)
                return;
            m_hideUnused = hideUnused;
            reloadTextures();
        }
        
        void TextureBrowserPanel::setGroup(bool group) {
            if (m_group == group)
                return;
            m_group = group;
            reloadTextures();
        }

        void TextureBrowserPanel::setSortCriterion(Model::Assets::ETextureSortCriterion criterion) {
            if (m_sortCriterion == criterion)
                return;
            m_sortCriterion = criterion;
            reloadTextures();
        }

        void TextureBrowserPanel::setFixedCellWidth(float fixedCellWidth) {
            m_layout.setFixedCellWidth(fixedCellWidth);
        }

        void TextureBrowserPanel::setFilterText(const std::string& filterText) {
            if (m_filterText.compare(filterText) == 0)
                return;
            m_filterText = filterText;
            reloadTextures();
        }
        
        TextureBrowserControl::TextureBrowserControl(Gwen::Controls::Base* parent, Controller::Editor& editor) : Gwen::Controls::Base(parent), m_editor(editor) {
            m_browserScroller = new Gwen::Controls::ScrollControl(this);
            m_browserScroller->Dock(Gwen::Pos::Fill);
            m_browserScroller->SetScroll(false, true);
            
            m_browserPanel = new TextureBrowserPanel(m_browserScroller, editor);
            m_browserPanel->Dock(Gwen::Pos::Top);
            m_browserPanel->SetPadding(Gwen::Padding(5, 5, 5, 5));
        }

        void TextureBrowserControl::Render(Gwen::Skin::Base* skin) {
            skin->DrawBox(this);
        }
        
        void TextureBrowserControl::setHideUnused(bool hideUnused) {
            m_browserPanel->setHideUnused(hideUnused);
        }

        void TextureBrowserControl::setGroup(bool group) {
            m_browserPanel->setGroup(group);
        }
    
        void TextureBrowserControl::setSortCriterion(Model::Assets::ETextureSortCriterion criterion) {
            m_browserPanel->setSortCriterion(criterion);
        }
        
        void TextureBrowserControl::setFixedCellWidth(float fixedCellWidth) {
            m_browserPanel->setFixedCellWidth(fixedCellWidth);
        }
        
        void TextureBrowserControl::setFilterText(const std::string& filterText) {
            m_browserPanel->setFilterText(filterText);
        }
    }
}