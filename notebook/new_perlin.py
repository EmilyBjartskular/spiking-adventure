# %%
from perlin_noise import PerlinNoise
from random import randint
import math
import time

LEFT = -1
STILL = 0
RIGHT = 1

def direction(n_delta: int):
  # Left
  if n_delta < 0:
    return LEFT
  # Right
  return RIGHT

def gen_direction(N: int, tmax: int, dt: float, precision: int = 1):
  # Seed noise generator
  noise = PerlinNoise(octaves=4, seed=1)
  
  # Create a range from 0 to tmax / dt, step size is 1 (default)
  step_range = range(0, int(tmax / dt))
  size = len(step_range)
  
  # Multiply all values in step_range by dt
  t_range = [step * dt for step in step_range]
  
  # Using step_range as an intermediary for creating t_range 
  # prevents "wonky" behaviour from float precisions,
  # it guarantees the correct number of time steps (and size of dir_list)
  
  # Initialize a direction list
  dir_list = [None] * size
  
  i = 0
  last_n = 0
  t_delta_start = time.perf_counter()
  tc_start = time.perf_counter()
  while i < size:
    # Loop freely and only do calculations when we exceed dt
    # this makes things smoother (in theory) than using than stepping
    # This avoids the drift that time.sleep() would cause
    t_check = time.perf_counter()
    if t_check - t_delta_start > dt:
      t_delta_start = t_check
      
      # Calculate noise value from the current time step
      t = t_range[i]
      n = noise(t / precision)

      # Calculate noise delta and direction
      n_delta = n - last_n
      last_n = n
      d = direction(n_delta)
      dir_list[i] = d
      
      if (n_delta != 0):
        print(n_delta, n_delta / abs(n_delta))

      # 20 fps animation, does not affect output data
      # Only used for visualisation
      tc = time.perf_counter()
      if tc - tc_start > 0.05:
        tc_start = tc
        
      i += 1
  return dir_list

# %%
gen_direction(100, 5, 0.01, 9)

# %%
mx = 0
mn = 1

npn = PerlinNoise(octaves=4, seed=1)
for i in range(100000):
  nnn = npn(i / 100)
  if nnn < mn:
    mn = nnn
  if nnn > mx:
    mx = nnn

print('max: {:.5f}\tmin: {:.5f}'.format(mx, mn))

# %%
def new_gen(N: int, time: int, precision: int = 100):
  # Seed noise generator
  noise = PerlinNoise(octaves=3, seed=1)

  # Using step_range as an intermediary for creating t_range 
  # prevents "wonky" behaviour from float precisions,
  # it guarantees the correct number of time steps (and size of dir_list)
  
  # Initialize a direction list
  labels = [None] * time
  spikes = [None] * time
  times = [None] * time

  # Set first spike manually
  labels[0] = 0
  spikes[0] = round(N / 2)
  times[0] = 0
  
  t = 1
  i = 0
  id = round(N / 2)
  cooldown = 0

  # Inverts movement when hitting neuron edges
  dir = 1
  sign = 0
  while t < time:
    still = True
    if cooldown == 0:
      # 10% chance of standing still
      if randint(0, 9) is 0:
        cooldown = 3
      else:
        i += 1
        still = False
    else:
      cooldown -= 1
    
    # Get random value from the noise generator
    n_s = noise(i / precision)

    # Get Movement direction
    d = STILL if still is True else direction(n_s)
    
    # Check if movement would go out-of-bounds
    if id + d * dir < 0 or id + d * dir >= N:
      # Invert movement 
      dir *= -1
      sign = d

    # Do the movement
    id += d * dir
    
    #if sign is -1 and d in [0, 1] or sign is 1 and d in [-1, 0]:
    # If the original movement direction has changed, reset sign
    if sign not in [0, d]:
      # dir *= -1
      sign = 0

    #id = round(n_s * N + N / 2)
    #d = id - spikes[t - 1]

    labels[t] = d * dir
    spikes[t] = id
    times[t] = t

    if abs(d) > 1:
      print('!!!!!!!!!!!!!!!!!!!!!')
      print('id: {:d}\tlid: {:d}\td: {:d}'.format(id, spikes[t-1], d))
      break

   # print('t: {:4d}\ti: {:4d}\tid: {:4d}\td: {:4d}\tsign: {:4d}\tn_s: {:.5f}'
   #   .format(t, i, id, d * dir, sign, n_s), end='\n')
    t += 1

  return {
    'labels': labels,
    'spikes': spikes,
    'times': times
  }

data = new_gen(50, 10000)

l = list(zip(data['labels'], data['spikes'], data['times']))
#l

print(max(data['spikes']))
print(min(data['spikes']))