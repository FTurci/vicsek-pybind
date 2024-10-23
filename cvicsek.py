import myvic
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np
import sys

eta = float(sys.argv[1])
N = int(sys.argv[2])

system = myvic.System(N,10.0,0.05, eta)

system.random_start()
conf = np.asarray(system.get_config())
fig, ax= plt.subplots(figsize=(6,6))
 
qv = ax.quiver(conf[:,0], conf[:,1], np.cos(conf[0:,2]), np.sin(conf[:,2]), conf[:,2], clim=[-np.pi, np.pi], cmap=plt.cm.rainbow)
 
def animate(i):
    print(i)
    system.update()

    conf = np.asarray(system.get_config())
    pos = conf[:,:2]
    qv.set_offsets(pos)
    qv.set_UVC(np.cos(conf[0:,2]), np.sin(conf[:,2]), conf[:,2])
    return qv,
 
anim = FuncAnimation(fig,animate,np.arange(1, 200),interval=1, blit=True)
plt.show()