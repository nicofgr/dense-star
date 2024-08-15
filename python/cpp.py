import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import AutoMinorLocator, MultipleLocator

plt.rcParams['text.usetex'] = True

#fig, ax1 = plt.subplots(5, figsize=(5.4, 9.6))
fig, ax1 = plt.subplots()
#-------------------------------------------------------
x = []
titles = []
titles.append('ud')
titles.append('uds')
titles.append('udsc')
titles.append('udscb')
titles.append('udscbt')
dirs = []
dirs.append('../cpp/output/ud.dat')
dirs.append('../cpp/output/uds.dat')
dirs.append('../cpp/output/udsc.dat')
dirs.append('../cpp/output/udscb.dat')
dirs.append('../cpp/output/udscbt.dat')
cols = []
cols.append('b')
cols.append('g-.')
cols.append('c--')
cols.append('r:')
cols.append('m')


ax1.set_title("Pressão e massa por raio para B=155MeV")
ax1.set_xlabel(r'$r$ (km)')
ax1.set_ylabel(r'$p$ (MeV/f$m^3$)')
ax1.set_xlim([0,11])
ax1.xaxis.set_major_locator(MultipleLocator(2))
ax1.xaxis.set_minor_locator(MultipleLocator(1))
ax1.set_ylim([0,200])
ax2 = ax1.twinx()
ax2.set_ylabel(r'$m/M_\odot$')
ax2.set_ylim([0,2.1])
ax2.yaxis.set_major_locator(MultipleLocator(0.4))
ax2.yaxis.set_minor_locator(MultipleLocator(0.2))

for i in range(5):
    x.append([])
    with open(dirs[i], 'r') as f:
        lines = f.readlines()
        x[i].append([float(line.split()[0]) for line in lines])
        x[i].append([float(line.split()[1]) for line in lines])
        x[i].append([float(line.split()[2]) for line in lines])

    ax1.plot(x[i][0],x[i][1], cols[i], label=titles[i])
    ax2.plot(x[i][0],x[i][2], cols[i])


#fig.suptitle(':)', fontsize=16)
#fig.tight_layout(pad = 4.0)
ax1.legend(loc='upper center')
plt.show()
