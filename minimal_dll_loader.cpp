#include <windows.h>
#include <fstream>


std::ofstream log_file("ecs_test_sys.log", std::ios::out);

extern "C" {


    __declspec(dllexport) bool mb_ecs_sys_init_test() {
        try {
            log_file << "[mb_ecs_sys_init_test] Library initialized successfully." << std::endl;
            return true;
        } catch (...) {
            log_file << "[mb_ecs_sys_init_test] Failed to retrieve init-library entrypoint from system library ecs_test_sys.dll" << std::endl;
            return false;
        }
    }

    __declspec(dllexport) int32_t __stdcall mb_ecs_set_kernel(void* ptr) {
        if (ptr) {
            log_file << "[mb_ecs_set_kernel] ptr set successfully." << std::endl;
            return 0;
        } else {
            log_file << "[mb_ecs_set_kernel] Invalid ptr pointer passed." << std::endl;
            return -1;
        }
    }

    __declspec(dllexport) int32_t __stdcall mb_ecs_report_component_libraries(int32_t var, char* char_buffer, int32_t size) {
        log_file << "[mb_ecs_report_component_libraries] Reporting var in mb_ecs_report_component_libraries: " << var << std::endl;
        return 0;
    }

    __declspec(dllexport) int32_t __stdcall mb_ecs_report_component_library_version(const char* var, char* char_buffer, int32_t size) {
        log_file << "[mb_ecs_report_component_library_version] Reporting var in mb_ecs_report_component_library_version: " << var << std::endl;
        return 0;
    }

    __declspec(dllexport) uint32_t __stdcall mb_ecs_report_components(uint32_t var, const char** char_buffer1, const char** char_buffer2, uint32_t* size1, uint32_t* size2, void* ptr1, void* ptr2) {
        log_file << "[mb_ecs_report_components] Reporting mb_ecs_report_components: " << var << std::endl;
        return 0;
    }

    __declspec(dllexport) void __stdcall mb_ecs_exit_system_library() {
        log_file << "[mb_ecs_exit_system_library] Exiting system library." << std::endl;
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            if (!log_file.is_open()) {
                log_file.open("ecs_test_sys.log", std::ios::app);
            }


            log_file << "DLL loaded." << std::endl;

            break;

        case DLL_PROCESS_DETACH:

            log_file << "DLL unloaded." << std::endl;
            if (log_file.is_open()) {
                log_file.close();
            }
            break;

        default:;
    }
    return TRUE;
}
