# PF2-Tools
Basic tools for Pre-Fortress 2 dedicated server development

### Windows Servers are partially supported (no PF2 unique functions, just working VGUI menus and other SM features)


This program comes with base SourceMod gamedata.

# Wiki
Please visit our [wiki pages](https://github.com/dangreene0/PF2-Tools/wiki) for more information on PF2-Tools or adding automatic signature scanning to your Source Mod.

# Requirements
You must install sourcemod [1.10.0.6502](https://www.sourcemod.net/downloads.php?branch=1.10-dev&all=1) & [DHooks](https://github.com/peace-maker/DHooks2/releases) (`dhooks-2.2.0-detours17-sm110.zip` version) and the latest version of [Metamod](https://www.sourcemm.net/downloads.php?branch=stable)

### Usage ###
The main purpose of the this is to remap the natives and forwards signatures that TF2 plugins rely on from the TF2 extension and have them point to the plugin instead. This is because loading the extension on PF2 is impossible without a custom build of SourceMod. To avoid that headache, simply edit and recompile plugins from TF2 (given that they work on PF2) and they will no longer rely on the TF2 extension.

Just go into the plugin(s) you want to use and change:
```cpp
#include <tf2>
// Or
#include <tf2_stocks>
```
To
```cpp
#include <pf2>
```

Be aware that a simple recompilation isn't a guaranteed import! Pre-Fortress does not support certain natives and behaviors that TF2 does.

# New forks

If you are interested in making a version for your own Source Mod, use [this video guide](https://youtu.be/SD6Rn2D7IGo) by the original creator to find the **digital signatures.**
