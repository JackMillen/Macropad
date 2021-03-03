#SingleInstance Force

F13::
Send, <EMAIL 1>
Return

+F13::
Send, <EMAIL 2>
Return

^F13::
Send, <EMAIL 3>
Return

F14::
Run, C:\Program Files (x86)\Steam\Steam.exe
return

F15::
Run, C:\Program Files (x86)\Google\Chrome\Application\chrome.exe
return

F16::
Run, https://www.youtube.com/watch?v=dQw4w9WgXcQ
return

F17::
Run, ms-settings:
return

F18::
Run, C:\Program Files\Ultimaker Cura 4.8.0\Cura.exe
return

F19::
Run, explorer.exe
return

F20::
Send, ^c
Sleep 50
Run, http://www.google.com/search?q=%clipboard%
Return

