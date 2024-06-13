import matplotlib.pyplot as plt 
import numpy as np
from matplotlib.ticker import AutoMinorLocator, MultipleLocator

#plt.rcParams['text.usetex'] = True


with open('fortran.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y1 = [float(line.split()[1]) for line in lines]
    y2 = [float(line.split()[2]) for line in lines]

fig, ax1 = plt.subplots(2, figsize=(6.4,9.6))

ax1[0].set_title(r'Fortran')
ax1[0].set_xlabel(r'$r$ (km)')
ax1[0].set_ylabel(r'$p$ (MeV/fm^3)')
ax1[0].set_xlim([0,11])
ax1[0].xaxis.set_major_locator(MultipleLocator(2))
ax1[0].xaxis.set_minor_locator(MultipleLocator(1))
ax1[0].set_ylim([0,160])
ax1[0].plot(x,y1, 'r:')

ax2 = ax1[0].twinx()
ax2.set_ylabel(r'$m/M_sol$')
ax2.set_ylim([0,2])
ax2.yaxis.set_major_locator(MultipleLocator(0.4))
ax2.yaxis.set_minor_locator(MultipleLocator(0.2))
ax2.plot(x,y2, 'r:')

#-------------------------------------------------------
with open('output/cpp.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y1 = [float(line.split()[1]) for line in lines]
    y2 = [float(line.split()[2]) for line in lines]

ax1[1].set_title(r'C++')
ax1[1].set_xlabel(r'$r$ (km)')
ax1[1].set_ylabel(r'$p$ (MeV/fm^3)')
ax1[1].set_xlim([0,11])
ax1[1].xaxis.set_major_locator(MultipleLocator(2))
ax1[1].xaxis.set_minor_locator(MultipleLocator(1))
ax1[1].set_ylim([0,160])
ax1[1].plot(x,y1, 'r:')

ax2 = ax1[1].twinx()
ax2.set_ylabel(r'$m/M_\odot\$')
ax2.set_ylim([0,2])
ax2.yaxis.set_major_locator(MultipleLocator(0.4))
ax2.yaxis.set_minor_locator(MultipleLocator(0.2))
ax2.plot(x,y2, 'r:')

fig.tight_layout()
plt.show()
