a='a'
b='b'
c='c'
d='d'
e='e'
f='f'
g='g'
h='h'
W='W'
Y='Y'
R='R'
O='O'
B='B'
G='G'
list_corner=[a,b,c,d,e,f,g,h]
list_edge=[1,2,3,4,5,6,7,8,9,10,11,12]
corner_permu=[a,b,c,d,e,f,g,h]
corner_ori  =[0,0,0,0,0,0,0,0]
edge_permu=[1,2,3,4,5,6,7,8,9,10,11,12]
edge_ori  =[0,0,0,0,0,0,0,0,0,0 ,0 ,0 ]

#color=[W,W,W,W,W,W,W,W,
#       R,R,R,R,R,R,R,R,
#       Y,Y,Y,Y,Y,Y,Y,Y,
#       B,B,B,B,B,B,B,B,
#       O,O,O,O,O,O,O,O,
#       G,G,G,G,G,G,G,G]
color=[O,W,W,O,W,O,W,W,
       W,R,R,W,R,W,R,R,
       R,Y,Y,R,Y,R,Y,Y,
       B,B,B,B,B,B,B,B,
       O,O,O,O,O,Y,Y,Y,
       G,G,G,G,G,G,G,G]

#color_of_corner=[[W,G,O],[W,O,B],[W,B,R],[W,R,G],[Y,O,G],[Y,B,O],[Y,R,B],[Y,G,R]]
#color_of_edge=[[W,O],[W,B],[W,R],[W,G],[O,G],[O,B],[R,B],[R,G],[Y,O],[Y,B],[Y,R],[Y,G]]
color_of_corner=[[W,O,G],[W,B,O],[W,R,B],[W,G,R],[Y,G,O],[Y,O,B],[Y,B,R],[Y,R,G]]
color_of_edge=[[W,O],[W,B],[W,R],[W,G],[O,G],[O,B],[R,B],[R,G],[Y,O],[Y,B],[Y,R],[Y,G]]

def create_corner(i):
    corner=[0,0,0]
    if i==1:
        corner=[color[0],color[39],color[42]]
    elif i==2:
        corner=[color[2],color[31],color[34]]
    elif i==3:
        corner=[color[7],color[10],color[26]]
    elif i==4:
        corner=[color[5],color[47],color[8]]
    elif i==5:
        corner=[color[21],color[45],color[37]]
    elif i==6:
        corner=[color[23],color[32],color[29]]
    elif i==7:
        corner=[color[18],color[24],color[15]]
    elif i==8:
        corner=[color[16],color[13],color[45]]
#    print corner
    corner2=corner[1:]
    corner2.insert(2,corner[0])
    corner3=corner2[1:]
    corner3.insert(2,corner2[0])
    for j in range(0,8):
        if corner==color_of_corner[j]:
            corner_ori[j]=0
            corner_permu[j]=list_corner[i-1]
 #           print list_corner[i-1]
            break
        elif corner2==color_of_corner[j]:
            corner_ori[j]=1
            corner_permu[j]=list_corner[i-1]
  #          print list_corner[j]
            break
        elif corner3==color_of_corner[j]:
            corner_ori[j]=-1
            corner_permu[j]=list_corner[i-1]
   #         print list_corner[j]
            break

#    print corner_ori[j],corner_permu[j]
#
#        else :
  #           print "error on create_corner"


def create_edge(i):
    edge=[]
    if i==1:
        edge=[color[1],color[36]]
    elif i==2:
        edge=[color[4],color[29]]
    elif i==3:
        edge=[color[6],color[9]]
    elif i==4:
        edge=[color[3],color[44]]
    elif i==5:
        edge=[color[38],color[41]]
    elif i==6:
        edge=[color[33],color[30]]
    elif i==7:
        edge=[color[12],color[25]]
    elif i==8:
        edge=[color[11],color[46]]
    elif i==9:
        edge=[color[22],color[35]]
    elif i==10:
        edge=[color[20],color[27]]
    elif i==11:
        edge=[color[17],color[14]]
    elif i==12:
        edge=[color[19],color[46]]
 #   print edge
    edge2=[edge[1],edge[0]]
    
    
    for j in range(0,12):
        if edge==color_of_edge[j]:
            edge_ori[j]=0
            edge_permu[j]=list_edge[i-1]

        elif edge2==color_of_edge[j]:
            edge_ori[j]=1
            edge_permu[j]=list_edge[i-1]

#    print edge_ori[j],edge_permu[j]
#        else :
 #           print "error on create_edge"




def create_cube():
    for i in range(1,9):
        create_corner(i)
    for i in range(1,13):
        create_edge(i)
    return corner_permu,corner_ori,edge_permu,edge_ori
    
