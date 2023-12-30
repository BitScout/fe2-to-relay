
# Seriellen Port ermitteln - funktioniert nicht, wenn mehrere vorhanden sind
$COM = [System.IO.Ports.SerialPort]::getportnames()

# Serielle Verbindung öffnen
$port= new-Object System.IO.Ports.SerialPort $COM,9600,None,8,one
$port.open()
# Das Öffnen des Ports resettet den Arduino, darum warten wir vor dem Senden kurz
sleep 3

# Sende "x", da der Arduino nur auf dieses Zeichen hört, um Fehlauslösungen zu vermeiden
$port.WriteLine("x")
$port.Close()
