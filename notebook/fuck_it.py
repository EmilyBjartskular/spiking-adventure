# %%
from random import randrange


def fuck_it(N: int, time: int, precision: int = 100):
  # Initialize a direction list
  labels = [None] * time
  spikes = [None] * time
  times = [None] * time

  # Set first spike manually
  labels[0] = 0
  spikes[0] = round(N / 2)
  times[0] = 0
  
  t = 1
  id = round(N / 2)
  cooldown = 0
  target = id
  dir = 0

  while t < time:
    # Get a target
    if id == target:
      while id == target:
        target = randrange(0, N)
      dir = round((target - id) / abs(target - id))
      #print(dir)

    # Check whether to move to stand still
    still = True
    if cooldown == 0:
      # 10% chance of standing still
      if randrange(0, 10) == 0:
        cooldown = 3
      else:
        still = False
    else:
      cooldown -= 1

    d = 0 if still == True else dir
    # Do movement
    id += d

    # Set output data
    labels[t] = d
    spikes[t] = id
    times[t] = t

    #print('t: {:1d}\tid: {:1d}\td: {:1d}\ttarget: {:1d}'.format(t, id, d, target), end='\n')
    t += 1

  return {
    'labels': labels,
    'spikes': spikes,
    'times': times
  }

data = fuck_it(10, 50)

l = list(zip(*[data[k] for k in data]))
l

#print(max(data['spikes']))
#print(min(data['spikes']))

# %%

def filter_spikes(data):
  z = list(zip(*[data[k] for k in data]))
  f = [r for r in z if r[0] != 0]
  v = [list(t) for t in zip(*f)]

  o = dict()
  for i, k in enumerate(data):
    o[k] = v[i]
  return o

f = filter_spikes(data)
f_ = list(zip(*[f[k] for k in f]))
f_