# FE2 to relay

Dieses Programm stellt eine EXE bereit, die beim Aufruf einen Befehl an die serielle Schnittstelle sendet.
Dort kann dann z. B. ein per USB angebundener Arduino einen Relais steuern und so einen Alarm an eine Gebäudesteuerung signalisieren.

Die EXE funktioniert auch so, wie im Repository hinterlegt, sie muss nicht zwingend neu gebaut werden.


## Bedeutung der Dateien

### `fe-to-relay.ps1`

Diese Datei enthält die Befehle, die bei einem Alarm ausgeführt werden sollen.
Sie wird in die `fe-to-relay.exe` verpackt.


### `fe-to-relay.exe`

Wird erzeugt mit der fe-to-relay.ps1 als Inhalt. Die EXE ist bei Alarm auszuführen, 
siehe auch https://alamos-support.atlassian.net/wiki/spaces/documentation/pages/219480642/Programm+ausf+hren


## Erzeugen der EXE

### ps2exe installieren

1. PowerShell-Konsole als Administrator öffnen
2. Den Befehl `Install-Module ps2exe` ausführen
3. Abfragen mit `j` bestätigen

### Umwandlung

1. In der Powershell in das Projektverzeichnis gehen und `ps2exe .\fe2-to-relay.ps1 .\fe2-to-relay.exe` ausführen
2. Falls ein Fehler gemeldet wird, `Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope Process` ausführen, 
um die Ausführung einmalig zu erlauben, dann obiges Kommando erneut versuchen.


## Danke an

- https://superuser.com/a/868341
- https://forum.arduino.cc/t/read-write-serial-communication-thru-cmd/331613
- https://batchloaf.wordpress.com/2013/02/12/simple-trick-for-sending-characters-to-a-serial-port-in-windows/

