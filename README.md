# preface_minimal_dll

A small project that attempts to create templates for extending [preface](https://store.steampowered.com/app/2820060/Preface_Undiscovered_World/).

Used tools: 
* Dependencies (https://github.com/lucasg/Dependencies)
* Binary Ninja (https://binary.ninja/)
to figure out the minimal set of symbols the engine needs to load a DLL

```
int32_t __stdcall mb_ecs_set_kernel(void* ptr)
int32_t __stdcall mb_ecs_report_component_libraries(int32_t var, char* char_buffer, int32_t size)
int32_t __stdcall mb_ecs_report_component_library_version(const char* var, char* char_buffer, int32_t size)
uint32_t __stdcall mb_ecs_report_components(uint32_t var, const char** cb1, const char** cb2, uint32_t* s1, uint32_t* s2, void* p1, void* p2)
void __stdcall mb_ecs_exit_system_library()
```


## compile 
```bash
mkdir build
cd build
cmake ..
cmake --build .
```


## Mod Preface

1. Go to the game's root directory.
2. Copy `ecs_test_sys.dll` (compiled before) 
3. Navigate to the `[game_root]/melba_config` folder.
4. Locate and open `system_libraries.sql`.
5. Before the COMMIT statement, add the following line (note that the version is important):

`INSERT INTO system_libraries VALUES('ecs_test_sys','1.0.0.0');`

5. To initialize the ECS component, use init_systems_module_scenario.sql and add, for example:

`INSERT INTO init_systems_module_scenario VALUES('mb_ecs_sys_init_test',0,1,1,NULL,NULL);`  

6 If you want to handle updates (to do something with the data), use `update_systems_module_scenario.sql` and add the relevant update statements there.



 


