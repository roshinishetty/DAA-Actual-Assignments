import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button, RadioButtons
import numpy as np
import csv


def get_coordinates(filename):
    with open(filename, newline='\n') as fptr:
        list_x = []
        list_y = []
        flag = 1
        for line in fptr.readlines():
            for u in line.split(','):
                #print(u[0])
                # list_x.append(float(u[0]))
                # list_y.append(float(u[1]))
                #print(u)
                if flag==1:
                    list_x.append(float(u))
                    flag=2
                else:
                    #u.rstrip('\n')
                    list_y.append(float(u))
                    flag=1    
    return (list_x, list_y)

# with open('input.csv') as csvfile:
#     data = [(int(x), int(y)) for x, y in csv.reader(csvfile, delimiter= ',')]

def draw_multiple_points(x1, y1, x21, y21, x22, y22, x23, y23):

    plt.style.use('seaborn-whitegrid')

    fig = plt.figure()

    #x_number_list = [1, 4, 9, 16, 25]
    #y_number_list = [1, 2, 3,4 , 5]
    plt.scatter(x1, y1, s=10, color = 'red')
    #plt.scatter(x_number_list, y_number_list, s=10, color = 'red')
    plt.axis('tight')

    #x_number_list = [1, 2, 3, 4, 5]
    #y_number_list = [1, 4, 9, 12, 15]
    plt.plot(x21, y21, linewidth=1, color='red', linestyle = 'solid') 
    plt.plot(x22, y22, linewidth=1, color='blue', linestyle = 'solid') 
    plt.plot(x23, y23, linewidth=1, color='green', linestyle = 'solid')   
    #plt.plot(x_number_list, y_number_list, linewidth=1, color='blue', linestyle = 'solid')    

    plt.tick_params(axis='both', labelsize=9)
    
    plt.title("Best Fit Lines")

    plt.xlabel("X")
    plt.ylabel("Y")

    plt.show()
    fig.savefig('Best Fit Lines.png')

if __name__ == '__main__':
    (input_x, input_y) = get_coordinates("input.csv")
    #print(input_x)
    #print(input_y)
    (output1_x, output1_y) = get_coordinates("output1.csv")
    (output2_x, output2_y) = get_coordinates("output2.csv")
    (output3_x, output3_y) = get_coordinates("output3.csv")
    draw_multiple_points(input_x, input_y, output1_x, output1_y, output2_x, output2_y, output3_x, output3_y)

