import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

def get_coordinates(filename):
    fptr = open(filename, "r")
    list_x = []
    list_y = []
    flag = 1
    for line in fptr.readlines():
        for u in line.split(', '):
                if flag==1:
                    list_x.append(float(u))
                    flag=2
                else:
                    #u.rstrip('\n')
                    list_y.append(float(u))
                    flag=1    
    return (list_x, list_y)


def draw_multiple_points(x1, y1, x2, y2):

    plt.style.use('seaborn-whitegrid')

    fig = plt.figure()

    #x_number_list = [1, 4, 9, 16, 25]
    #y_number_list = [1, 2, 3,4 , 5]
    plt.scatter(x1, y1, s=10, color = 'red')
    #plt.scatter(x_number_list, y_number_list, s=10, color = 'red')
    plt.axis('tight')

    #x_number_list = [1, 2, 3, 4, 5]
    #y_number_list = [1, 4, 9, 12, 15]
    plt.plot(x2, y2, linewidth=1, color='blue', linestyle = 'solid')   
    #plt.plot(x_number_list, y_number_list, linewidth=1, color='blue', linestyle = 'solid')    

    plt.tick_params(axis='both', labelsize=9)
    
    plt.title("Best Fit Lines")

    plt.xlabel("X")
    plt.ylabel("Y")

    plt.show()
    fig.savefig('Best Fit Lines.png')

if __name__ == '__main__':
    (input_x, input_y) = get_coordinates("input.txt")
    #print(input_x)
    #print(input_y)
    (output_x, output_y) = get_coordinates("output.txt")
    draw_multiple_points(input_x, input_y, output_x, output_y)

