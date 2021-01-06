# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %%
from ipycanvas import MultiCanvas, hold_canvas
from perlin_noise import PerlinNoise
import ipywidgets as ipw
import IPython.display as ipd
import time

width = 500
height = 30
canvas = MultiCanvas(width=width, height=height)
canvas[0].fill_style = '#000000'
canvas[0].fill_rect(0, 0, width, height)
ipd.display(canvas)

LEFT = -1
STILL = 0
RIGHT = 1

def direction(n_delta, thresh = 0.005):
    # Left
    if n_delta < -thresh:
        return -1
    # Right
    if n_delta > thresh:
        return 1
    # Still
    return 0

def gen_direction(tmax, dt, precision = 1):
    # Seed noise generator
    noise = PerlinNoise(octaves=4, seed=1)
    
    i = 0
    t = 0
    last_n = 0
    t_delta_start = time.perf_counter()
    tc_start = time.perf_counter()
    while True:
        # Loop freely and only do calculations when we exceed dt
        # this makes things smoother (in theory)
        t_delta = time.perf_counter()
        if t_delta - t_delta_start > dt:
            t_delta_start = t_delta
            
            n = noise(t / precision)

            n_delta = n - last_n
            last_n = n
            d = direction(n_delta)

            # 50 fps
            tc = time.perf_counter()
            if tc - tc_start > 0.05:
                tc_start = tc
                
                # For drawing
                with hold_canvas(canvas):
                    # Clear display
                    canvas[1].clear()
                    # Change color of circle if the output data says it's standing still
                    if d == STILL:
                        canvas[1].fill_style = '#ffff00'
                    else:
                        canvas[1].fill_style = '#ffffff'
                    x = n * width + width / 2
                    canvas[1].fill_circle(x, height / 2, height / 2)
                    print('\rn = {:8.5f}, x = {:8.5f}'.format(n, x), end='')
            t += dt

gen_direction(5, 0.01, 9)


# %%
import time

bla_old = time.perf_counter()
i = 0
while True:
    print(f'\r{i}', end='')
    i += 1


