
#include "gcc-plugin.h"
#include "plugin-version.h"
#include <stdio.h>

int plugin_is_GPL_compatible = 1;

int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
    if (!plugin_default_version_check (version, &gcc_version))
        return 1;

    printf("hello plugin!\n");
    return 0;
}
