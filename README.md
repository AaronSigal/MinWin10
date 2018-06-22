# MinWin10

Changelog:

- Added C++ wrapper
- Gathered a base of bloatware apps to begin adding to pre-configured debloat routines.

12/4/17
- Added support for the scanning and cataloging of installed apps
- Added support for filtering apps by bool:framework
- Located possible workaround for removing false-frameworked bloat, like Asphalt 8
- Resolved Bug: No longer fails to uninstall apps from entire system
- Identified method to consistently remove apps via the tag, even if the version number changes

1/19/18
- Made outputs less verbose
- Added support for logging
- Added support for error recording
- Added support for outputting log to a file
- Added support for detecting driver packages and other hardware utility packages in 3Db's package scanner
- Fist successful run of the 3Db preset

1/21/18
- Fixed several bugs related to launching powershell scripts
- Revised log verbage

1/24/18
- Moved project to Github


Planned Features:
- Add command line arguments that will allow one to disable logging
- Add Whitelist/Blacklist support
- Add loadable/custom list support
- Allow internet-enabled updating of pre-configured debloat routines
- Design custom scripting language to allow for more robust actions to be run on routine


Known bugs: 

- Fails to remove certain apps like Asphalt 8.
- When not run as admin, program fails
- Log isn't named by date
