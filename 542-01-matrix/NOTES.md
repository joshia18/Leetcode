this second method is like what if the value is already calculated in teh adjacent cells of 1 to calculate it's minimum value
first: calculate minimum of top and left cells, traversing from top to bottom
second: calculate the minimum of the present cell and min(right, bottom)+1, in the second step all the wrong values will get updated