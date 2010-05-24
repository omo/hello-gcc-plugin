
#include "gcc-plugin.h"
#include "plugin-version.h"
#include <stdio.h>

int plugin_is_GPL_compatible = 1;

void plugin_hook(void* gcc_data, void* user_data)
{
    printf("hello hook for %s!\n", (const char*)user_data);
}

int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
    const char* n = NULL;

    if (!plugin_default_version_check (version, &gcc_version))
        return 1;

    printf("hello plugin!\n");

    n = plugin_info->base_name;
    /* from cp/ */
    register_callback(n, PLUGIN_START_UNIT, &plugin_hook, "PLUGIN_START_UNIT");
    register_callback(n, PLUGIN_FINISH_UNIT, &plugin_hook, "PLUGIN_END_UNIT");
    register_callback(n, PLUGIN_PRE_GENERICIZE, &plugin_hook, "PLUGIN_PRE_GENERICIZE");
    register_callback(n, PLUGIN_FINISH_TYPE, &plugin_hook, "PLUGIN_FINISH_TYPE");
    
    return 0;
}
