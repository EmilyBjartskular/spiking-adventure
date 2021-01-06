# %%
from random import random, randrange


def spikegen(N: int, time: int, precision: int = 100, random_start: bool = False):
  # Initialize a direction list
  labels = [None] * time
  spikes = [None] * time
  times = [None] * time

  if random_start:
    start_place = randrange(0, N)
  else:
    start_place = round(N/2)

  # Set first spike manually
  labels[0] = 0
  spikes[0] = start_place
  times[0] = 0
  
  t = 1
  id = start_place
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
      if randrange(0, 20) == 0:
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

data = spikegen(100, 100)

l = list(zip(data['labels'], data['spikes'], data['times']))

print(data['labels'])
print(data['spikes'])
print(data['times'])
#print(l)
