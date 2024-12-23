# preface_minimal_dll


## compile 
```bash
mkdir build
cd build
cmake ..
cmake --build .
```


## Mod Preface

1. Go to the game's root directory.
2. Navigate to the melba_config folder.
3. Locate and open system_libraries.sql.
4. Before the COMMIT statement, add the following line (note that the version is important):

`INSERT INTO system_libraries VALUES('ecs_test_sys','1.0.0.0');`

5. To initialize the ECS component, use init_systems_module_scenario.sql and add, for example:

`INSERT INTO init_systems_module_scenario VALUES('mb_ecs_sys_init_test',0,1,-1,NULL,NULL);`

6 If you want to handle updates (to do something with the data), use `update_systems_module_scenario.sql` and add the relevant update statements there.



 


