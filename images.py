import matplotlib.pyplot as plt

#plt.rcParams['text.usetex'] = True

with open('MQ-mpXrn.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y1 = [float(line.split()[1]) for line in lines]
    y2 = [float(line.split()[2]) for line in lines]

fig, ax1 = plt.subplots(2, figsize=(6.4,9.6))

ax1[0].set_title('Fortran')
ax1[0].set_xlabel('$r$ (km)')
ax1[0].set_ylabel('$p$ (MeV/fm^3)')
ax1[0].set_xlim([0,11])
#ax1.set_ylim([0,160])
ax1[0].plot(x,y1)

ax2 = ax1[0].twinx()
ax2.set_ylabel('$m/M_sol$')
ax2.set_ylim([0,2])
ax2.plot(x,y2)


with open('data.dat', 'r') as f:
    lines = f.readlines()
    x = [float(line.split()[0]) for line in lines]
    y1 = [float(line.split()[1]) for line in lines]
    y2 = [float(line.split()[2]) for line in lines]

ax1[1].set_title('C++')
ax1[1].set_xlabel('$r$ (km)')
ax1[1].set_ylabel('$p$ (MeV/fm^3)')
ax1[1].set_xlim([0,11])
#ax1.set_ylim([0,160])
ax1[1].plot(x,y1)

ax2 = ax1[1].twinx()
ax2.set_ylabel('$m/M_sol$')
ax2.set_ylim([0,2])
ax2.plot(x,y2)

fig.tight_layout()
plt.show()
