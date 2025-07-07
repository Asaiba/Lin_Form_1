import matplotlib.pyplot as plt
import matplotlib.animation as animation
from sensor_module import get_sensor_data
import time

# Store data
temperature_data = []
humidity_data = []
battery_data = []
timestamps = []

start_time = time.time()

def update(frame):
    elapsed = time.time() - start_time
    if elapsed > 30:
        ani.event_source.stop()
        return

    temp, hum, batt = get_sensor_data()
    current_time = round(elapsed, 1)

    timestamps.append(current_time)
    temperature_data.append(temp)
    humidity_data.append(hum)
    battery_data.append(batt)

    ax1.clear()
    ax2.clear()
    ax3.clear()

    ax1.plot(timestamps, temperature_data, 'r-')
    ax2.plot(timestamps, humidity_data, 'b-')
    ax3.plot(timestamps, battery_data, 'g-')

    ax1.set_title("Temperature (°C)")
    ax2.set_title("Humidity (%)")
    ax3.set_title("Battery Level (%)")

    ax1.set_ylim(0, 60)
    ax2.set_ylim(0, 110)
    ax3.set_ylim(0, 110)

    plt.tight_layout()

# Setup plots
fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(10, 6))
ani = animation.FuncAnimation(fig, update, interval=2000)

plt.show()
