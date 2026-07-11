import serial, time, sys
port = sys.argv[1] if len(sys.argv) > 1 else 'COM5'
secs = int(sys.argv[2]) if len(sys.argv) > 2 else 15
s = serial.Serial(port, 115200, timeout=0.2)
s.setDTR(False); s.setRTS(True); time.sleep(0.15); s.setRTS(False)
end = time.time() + secs
try:
    while time.time() < end:
        d = s.read(4096)
        if d: sys.stdout.buffer.write(d); sys.stdout.buffer.flush()
finally:
    s.close()
