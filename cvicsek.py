import myvic
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np
import sys
import cmasher

eta = float(sys.argv[1])
N = int(sys.argv[2])
Lx = 60.0
Ly = 15.0
system = myvic.System(N, Lx, Ly, 0.1, eta)

system.random_start()
conf = np.asarray(system.get_config())
scale = 5.0
fig, ax= plt.subplots(figsize=(Lx/scale,Ly/scale))
 
qv = ax.quiver(conf[:,0], conf[:,1], np.cos(conf[0:,2]), np.sin(conf[:,2]), conf[:,2], clim=[-np.pi, np.pi], cmap=cmasher.infinity_s, scale=1, scale_units='xy', angles='xy' , alpha=0.5)
plt.axis('equal')
plt.axis('off')
 
A = 0.06
B = 0.14
def animate(i):
    print(i,system.noise)
    # for k in range(3):
    system.update()
    # system.noise = A*np.sin(2*np.pi*i/500.0)+B
    conf = np.asarray(system.get_config())
    pos = conf[:,:2]
    qv.set_offsets(pos)
    qv.set_UVC(np.cos(conf[0:,2]), np.sin(conf[:,2]), conf[:,2])
    
    return qv,
 
anim = FuncAnimation(fig,animate,np.arange(1, 1000),interval=1, blit=True)
anim.save('animation.gif', writer='imagemagick', fps=50)
# plt.show()