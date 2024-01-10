
# Seriellen Port ermitteln - funktioniert nicht, wenn mehrere vorhanden sind
$COM = [System.IO.Ports.SerialPort]::getportnames()
Write-Host "Gefundene Ports: $COM"

$portList = $COM.Split(" ")

foreach($portName in $portList) {
	Write-Host "Versuche Port $portName"

	# Serielle Verbindung öffnen
	$port= new-Object System.IO.Ports.SerialPort $portName,9600,None,8,one
	$port.ReadTimeout = 200
	$port.WriteTimeout = 200
	
	$port.open()
	# Das Öffnen des Ports resettet den Arduino, darum warten wir vor dem Senden kurz
	Start-Sleep -Seconds 1

	# Sende "x", da der Arduino nur auf dieses Zeichen hört, um Fehlauslösungen zu vermeiden
	$port.WriteLine("x")
	$port.Close()
}

Write-Host "Programm wird nach 30 Sekunden geschlossen..."
Start-Sleep -Seconds 30
