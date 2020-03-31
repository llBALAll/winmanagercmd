# winmanagercmd
Run Resize and Reposition your Apps with one shortcut

<h3 align="center">
  <img src="images/pscr.png" alt="Logomarca" />
</h3>

With all config done, just one shortcut do all you need.

Steps: 
- Create a new batch file with commands to Run Resize and Reposition your common aplications;

ex2.bat: 
	rem command for open a program without passing argument for it
	start /min C:\winmanagercmd\bin\Release\winmanagercmd.exe C:\winmanagercmd\cmd1.bat "" "cmd1.bat" 1000 140 905 895
	rem command for open a program passing argument for it
	start /min C:\winmanagercmd\bin\Release\winmanagercmd.exe "C:\Sublime Text Build 3176 x64\sublime_text.exe" "C:\winmanagercmd\winmanagercmd.cpp" "C:\winmanagercmd\winmanagercmd.cpp - Sublime Text (UNREGISTERED)" 101 140 884 894

- Create a shortcut for the batch file and insert a key shortcut by right click on shortcut addind the key shortcut

<h3 align="center">
  <img src="images/pscr1.png" alt="Logomarca" />
</h3>

- Put the shortcut on desktop to be able to use

## Créditos
[llBALAll](https://github.com/llBALAll)