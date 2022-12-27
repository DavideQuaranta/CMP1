# ONLY for Jupyter notebook
#%matplotlib notebook
#%matplotlib inline

# Import modules
import matplotlib.pyplot as plt
import math
import numpy as np

# Gravity!
g = 9.8   # m/s^2

# Function to test values provided for initial conditions or integration settings
# The 4 parameters that the user may want to customize are:
# 1) the time step (dt)
# 2) the angle at which the bullet is shot (theta)
# 3) the height from which the bullet is shot (h)
# 4) the speed at which the bullet is shot (v0)
def test_val(var, val):
    test = False
    # Accept integration steps and initial velocities only if > 0
    if var in ['dt', 'v0']:
        test = val>0
    # Accept initial height >= 0
    elif var=='h':
        test = val>=0
    # Assuming that val can only be 'theta' at this point
    # allow only 0 < theta < 90 [degrees]
    else:
        test = (val>0 and val<90)

    return test
        

# Function to handle reading in initial conditions and integration settings
def set_param(var):
    # Dictionary of default values
    defaults = {
        'dt':     0.01, # [s] Default value of the time step
        'theta': 23.,  # [deg] Default value of the angle at which the bullet is shot
        'h':      5.,  # [m] Default value of the height from which the bullet is shot
        'v0':     10., # [m/s] Default value of the speed at which the bullet is shot
    }
    # Dictionary of info messages to the user
    msgs = {
        'dt': "Insert dt > 0 in sec (press return for {0} sec): ".format(defaults['dt']),
        'theta': "Insert angle theta in (0,90) degrees (press return for {0} degrees): ".format(defaults['theta']),
        'h': "Insert initial height h in m: (press return for h = {0} m): ".format(defaults['h']),
        'v0': "Insert v_0 > 0 in m/s (press return for {0} m/s): ".format(defaults['v0'])
    }
    # Start by reading a value and continue until happy with value provided
    while True:
        val_in = input(msgs[var])
        # Allow default value
        if val_in=="":
            val_out = defaults[var]
            break
        # Convert to float...
        try:
            val_out = float(val_in)
        except:
            val_out = -1
        # ...and test value
        if test_val(var, val_out):
            break

    # Convert theta from degrees to radians
    if var=='theta':
        val_out = math.radians(val_out)
    
    return val_out


# Offer the user the chance to customize values of dt, theta, h, v0
dt = set_param('dt')
theta = set_param('theta')
h = set_param('h')
v0 = set_param('v0')

# Compute initial velocity components
v0x = v0*math.cos(theta)
v0y = v0*math.sin(theta)
print("v0_x: %.3f m/s \t v0_y: %.3f m/s"%(v0x,v0y))

# Initial position coordinates
x0 = 0
y0 = h

# "Evolution" functions
def x(t):
    return x0 + v0x*t

def y(t):
    return y0 + v0y*t - 0.5*g*t*t

# Generate list of times for sampling
times = np.arange(0., 1000., dt).tolist() 

# Print first 10 elements
print(times[:10])

# Compute x(t_i)
xi = [x(t) for t in times if y(t)>=0.]

# Compute y(t_i)
yi = [y(t) for t in times if y(t)>=0.]

print( "total steps:\t %-4d"%len(xi))
print( "last x:\t\t %.2f"%xi[-1])
print( "last y:\t\t %.3f"%yi[-1])

# Plot results...
plt.plot(xi, yi, label='trajectory', color='red', marker='.')
plt.legend()

# ...and make them look good
plt.title('motion under gravity')
plt.xlabel("x [m]")
plt.ylabel("y [m]")
plt.grid(True)
plt.xlim(-0.01, max(xi)*1.1)
plt.ylim(-0.01,max(yi)*1.10)

# Only for script
plt.show()
# or use this to save your plot
#plt.savefig("./gravity.png")
