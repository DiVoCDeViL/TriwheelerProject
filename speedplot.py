import numpy as np
import matplotlib.pyplot as plt

# Given values
L = 3.5
w = 1.5
Vl = 40
q = np.linspace(-45, 45, 100)  # Angle in degrees

# Converting degrees to radians
q_rad = np.radians(q)

# Calculate Vi and Vo
Vi = Vl * (1 - (w * np.tan(q_rad)) / (2 * L))
Vo = Vl * (1 + (w * np.tan(q_rad)) / (2 * L))

# Plot q vs Vi
plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(q, Vi, label='Vi')
plt.xlabel('q (degrees)')
plt.ylabel('Vi')
plt.title('q vs Vi')
plt.grid(True)

# Plot q vs Vo
plt.subplot(1, 2, 2)
plt.plot(q, Vo, label='Vo')
plt.xlabel('q (degrees)')
plt.ylabel('Vo')
plt.title('q vs Vo')
plt.grid(True)

plt.tight_layout()
plt.show()



