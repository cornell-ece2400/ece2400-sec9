#=========================================================================
# slist-int-reverse-v1-v2-ploy.py
#=========================================================================
# Simple python script for plotting measured execution time and doing a
# polynomial fit using matplotlib and numpy.
#
# Author : Christopher Batten
# Date   : October 14, 2021

def plot_data( ax, result_filename, marker, label ):

  # data arrays

  n = []
  t = []

  # Make sure results file exists

  if not os.path.exists(result_filename):
    return

  # Read data from results file

  with open(result_filename) as f:
    for line in f:
      if "Fill and reverse with size" in line:
        n.append( float(line.split()[5]) )
      if "Average: elapsed time" in line:
        t.append( float(line.split()[4]) )

  # Plot the data

  ax.plot( n, t, marker=marker, label=label )

# Set the backend to PDF to avoid using the GUI

import matplotlib
matplotlib.use('PDF')

# Import matplotlib for plotting and numpy for data analysis

import matplotlib.pyplot as plt
import numpy as np

# Import other Python packages

import os

# Create the figure and axis for our plot

fig, ax = plt.subplots()

# Plot the data

plot_data( ax, "slist-int-reverse-v1-eval.txt",   'o', "SListInt::reverse_v1"   )
plot_data( ax, "slist-int-reverse-v2-eval.txt",   '^', "SListInt::reverse_v2"   )
plot_data( ax, "slist-dpoly-reverse-v1-eval.txt", 's', "SListDpoly::reverse_v1" )
plot_data( ax, "slist-dpoly-reverse-v2-eval.txt", 'x', "SListDpoly::reverse_v2" )

# Add some labels, grid, an save to a PDF

ax.set( xlabel="Input Array Size", ylabel="Measured Execution Time (s)" )
ax.grid()
ax.legend()

fig.savefig( "slist-reverse-plot.pdf", bbox_inches='tight' )

