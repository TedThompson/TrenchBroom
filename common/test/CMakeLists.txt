set(COMMON_TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(COMMON_TEST_UTILS_SOURCE
        "${COMMON_TEST_SOURCE_DIR}/Assets/EntityDefinitionTestUtils.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Assets/EntityDefinitionTestUtils.h"
        "${COMMON_TEST_SOURCE_DIR}/IO/TestEnvironment.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/TestEnvironment.h"
        "${COMMON_TEST_SOURCE_DIR}/IO/TestParserStatus.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/TestParserStatus.h"
        "${COMMON_TEST_SOURCE_DIR}/Catch2.h"
        "${COMMON_TEST_SOURCE_DIR}/QtPrettyPrinters.h"
        "${COMMON_TEST_SOURCE_DIR}/RunAllTests.cpp"
        "${COMMON_TEST_SOURCE_DIR}/TestLogger.cpp"
        "${COMMON_TEST_SOURCE_DIR}/TestPreferenceManager.cpp"
        "${COMMON_TEST_SOURCE_DIR}/TestPreferenceManager.h"
        "${COMMON_TEST_SOURCE_DIR}/TestUtils.cpp"
        "${COMMON_TEST_SOURCE_DIR}/TestUtils.h"
)

set(COMMON_TEST_SOURCE
        "${COMMON_TEST_SOURCE_DIR}/Assets/AssetUtilsTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Assets/ModelDefinitionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/EL/ELTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/EL/ExpressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/EL/InterpolatorTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/AseParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/AssimpParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/CompilationConfigParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/DefParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/DiskFileSystemTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/DkPakFileSystemTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/ELParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/EntParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/EntityDefinitionParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/EntityModelTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/FgdParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/FreeImageTextureReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/GameConfigParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/GameEngineConfigParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/HlMipTextureReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/IdMipTextureReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/IdPakFileSystemTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/M8TextureReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/Md3ParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/MdlParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/NodeReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/NodeWriterTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/ObjParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/ObjSerializerTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/PathTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/PathSuffixNameStrategyTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/Quake3ShaderFileSystemTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/Quake3ShaderParserTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/ReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/ResourceUtilsTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/TextureLoaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/TokenizerTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/WadFileSystemTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/WalTextureReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/WorldReaderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/ZipFileSystemTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/BezierPatchTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/BrushBuilderTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/BrushFaceTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/BrushNodeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/BrushTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/EditorContextTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/EntityNodeIndexTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/EntityNodeLinkTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/EntityNodeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/EntityRotationTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/EntityTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/GameFactoryTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/GameTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/GroupTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/GroupNodeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/IssueTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/LayerNodeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/ModelUtilsTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/NodeCollectionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/NodeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/PatchNodeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/PointTraceTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/PolyhedronTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/PortalFileTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/TaggingTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/TestGame.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/TestGame.h"
        "${COMMON_TEST_SOURCE_DIR}/Model/TexCoordSystemTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/WorldNodeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Renderer/AllocationTrackerTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Renderer/CameraTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Renderer/VertexTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/AddNodesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/ActionContextTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/AutosaverTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/ChangeBrushFaceAttributesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/ClipToolControllerTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/CommandProcessorTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/CompilationRunnerTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/CopyPasteTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/CsgTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/GridTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/GroupNodesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/HandleDragTrackerTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/InputEventTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/LayerNodesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/MapDocumentTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/MapDocumentTest.h"
        "${COMMON_TEST_SOURCE_DIR}/View/MoveHandleDragTrackerTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/RemoveNodesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/ExtrudeToolTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/ReparentNodesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/RepeatableActionsTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/PickingTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/ScaleObjectsToolTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/SelectionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/SelectionToolTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/SetEntityPropertiesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/SetLockStateTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/SetVisibilityStateTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/SnapBrushVerticesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/SwapNodeContentsTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/TagManagementTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/TextOutputAdapterTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/TransformNodesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/UndoTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/UpdateLinkedGroupsCommandTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/UpdateLinkedGroupsHelperTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/View/ValidatorTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/AABBTreeStressTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/AABBTreeTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/EnsureTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/NotifierTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/PreferencesTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/StackWalkerTest.cpp"
)

set(COMMON_REGRESSION_TEST_SOURCE
        "${COMMON_TEST_SOURCE_DIR}/IO/AseParserRegressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/WorldReaderRegressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/Md3ParserRegressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/IO/Quake3ShaderParserRegressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/BrushNodeRegressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/BrushRegressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/EntityRegressionTest.cpp"
        "${COMMON_TEST_SOURCE_DIR}/Model/PolyhedronRegressionTest.cpp"
)


# Catch2 needs one source file to define a macro (in our case CATCH_CONFIG_RUNNER) before including
# catch.hpp. This needs to be excluded from unity builds, otherwise the macro wouldn't be defined
# before the first catch.hpp inclusion.
set_property(SOURCE "${COMMON_TEST_SOURCE_DIR}/RunAllTests.cpp" PROPERTY SKIP_UNITY_BUILD_INCLUSION ON)

# Organize files into IDE folders
source_group(TREE "${COMMON_TEST_SOURCE_DIR}" FILES ${COMMON_TEST_UTILS_SOURCE})
source_group(TREE "${COMMON_TEST_SOURCE_DIR}" FILES ${COMMON_TEST_SOURCE})

# Configure test fixture directories
set(TEST_FIXTURE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fixture")

add_library(common-test-utils OBJECT ${COMMON_TEST_UTILS_SOURCE})
set_compiler_config(common-test-utils)
target_include_directories(common-test-utils PUBLIC ${COMMON_TEST_SOURCE_DIR})
target_link_libraries(common-test-utils PRIVATE common Catch2::Catch2)

macro(configure_test_target TARGET)
    target_link_libraries(${TARGET} PRIVATE common common-test-utils Catch2::Catch2)
    set_target_properties(${TARGET} PROPERTIES AUTOMOC TRUE)

    set_compiler_config(${TARGET})

    # By default VS launches with a CWD one level up from the .exe (which is in a "Debug" subdirectory)
    # but we copy resources into the .exe's directory, and the tests expect the CWD to be the .exe's directory.
    set_target_properties(${TARGET} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${TARGET}>")

    set(TEST_RESOURCE_DEST_DIR "$<TARGET_FILE_DIR:${TARGET}>")
    set(TEST_FIXTURE_DEST_DIR "${TEST_RESOURCE_DEST_DIR}/fixture")

    if(WIN32)
        # Copy DLLs to app directory
        add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:assimp::assimp>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:freeimage::FreeImage>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:freetype>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:tinyxml2::tinyxml2>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:miniz::miniz>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:fmt::fmt>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:GLEW::GLEW>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Qt5::Widgets>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Qt5::Gui>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Qt5::Core>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Qt5::Svg>" "$<TARGET_FILE_DIR:${TARGET}>"
            COMMAND ${CMAKE_COMMAND} -E make_directory    "$<TARGET_FILE_DIR:${TARGET}>/platforms"
            COMMAND ${CMAKE_COMMAND} -E make_directory    "$<TARGET_FILE_DIR:${TARGET}>/styles"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Qt5::QWindowsIntegrationPlugin>" "$<TARGET_FILE_DIR:${TARGET}>/platforms"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Qt5::QWindowsVistaStylePlugin>" "$<TARGET_FILE_DIR:${TARGET}>/styles")
    endif()

    # Copy some resource files required when initializing TrenchBroomApp
    add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${APP_RESOURCE_DIR}/graphics/images" "${TEST_RESOURCE_DEST_DIR}/images")

    # Clear all fixtures
    add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E remove_directory "${TEST_FIXTURE_DEST_DIR}")

    # Copy test fixtures
    add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${TEST_FIXTURE_SOURCE_DIR}" "${TEST_FIXTURE_DEST_DIR}/test")

    # Copy game config files
    add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${APP_RESOURCE_DIR}/games" "${TEST_FIXTURE_DEST_DIR}/games")

    add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${APP_RESOURCE_DIR}/games-testing" "${TEST_FIXTURE_DEST_DIR}/games")
endmacro()

add_executable(common-test ${COMMON_TEST_SOURCE})
target_include_directories(common-test PRIVATE ${COMMON_TEST_SOURCE_DIR})
configure_test_target(common-test)

add_executable(common-regression-test ${COMMON_REGRESSION_TEST_SOURCE})
target_include_directories(common-regression-test PRIVATE ${COMMON_TEST_SOURCE_DIR})
configure_test_target(common-regression-test)

