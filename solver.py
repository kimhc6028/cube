from transformer import create_cube

import random

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

center=[R,B,O,G]
formula=""
num_rot90=0

def formula_rotater(lst):
    for this,nex in zip(formula_buf,formula_buf[1:]):
        if nex=='2':
            rotate(this)
            rotate(this)
        elif nex=='3':
            rotate(this)
            rotate(this)
            rotate(this)
        else:
            rotate(this)
    if formula_buf:
        if not formula_buf[-1]==('2' or '3'):
            rotate(formula_buf[-1])

def cross_solve():
    for i in range(0,4):
        global formula
        formula_buf=cross_solve_one()
        formula+=formula_buf
        for this,nex in zip(formula_buf,formula_buf[1:]):
            if nex=='2':
                rotate(this)
                rotate(this)
            elif nex=='3':
                rotate(this)
                rotate(this)
                rotate(this)
            else:
                rotate(this)
        if formula_buf:
            if not formula_buf[-1]==('2' or '3'):
                rotate(formula_buf[-1])
        rotate90()
        formula+="/"
def cross_solve_one():
    face=center[0]


    if face==R:
        goal=11
    elif face==B:
        goal=10
    elif face==O:
        goal=9
    elif face==G:
        goal=12

    now=edge_permu[list_edge.index(goal)]
    now_spin=edge_ori[list_edge.index(goal)]
    if now==1:
        if now_spin==0:
            return "U2F2"
        elif now_spin==1:
            return "RUR3F"
    elif now==2:
        if now_spin==0:
            return "UF2"
        elif now_spin==1:
            return "R3FR"
    elif now==3:
        if now_spin==0:
            return "F2"
        elif now_spin==1:
            return "RU3R3F"
    elif now==4:
        if now_spin==0:
            return "U3F2"
        elif now_spin==1:
            return "LF3L3"
    elif now==5:
        if now_spin==0:
            return "D3L3D"
        elif now_spin==1:
            return "D2BD2"
    elif now==6:
        if now_spin==0:
            return "DRD3"
        elif now_spin==1:
            return "D2B3D2"
    elif now==7:
        if now_spin==0:
            return "DR3D3"
        elif now_spin==1:
            return "F"
    elif now==8:
        if now_spin==0:
            return "D3LD"
        elif now_spin==1:
            return "F3"
    elif now==9:
        if now_spin==0:
            return "B2U2F2"
        elif now_spin==1:
            return "B3D3L3D"
    elif now==10:
        if now_spin==0:
            return "R2UF2"
        elif now_spin==1:
            return "RF"
    elif now==11:
        if now_spin==0:
            return ""
        elif now_spin==1:
            return "F3DR3D3"
    elif now==12:
        if now_spin==0:
            return "L2U3F2"
        elif now_spin==1:
            return "L3F3"
            
def solve_first():
    for i in range(0,4):
        global formula
        formula_buf=solve_first_one()
        formula+=formula_buf
        for this,nex in zip(formula_buf,formula_buf[1:]):
            if nex=='2':
                rotate(this)
                rotate(this)
            elif nex=='3':
                rotate(this)
                rotate(this)
                rotate(this)
            else:
                rotate(this)
        if formula_buf:
            if not formula_buf[-1]==('2' or '3'):
                rotate(formula_buf[-1])
        rotate90()
        formula+="/"

def solve_first_one():
    face=center[0]

    if face==R:
        goal=g
    elif face==B:
        goal=f
    elif face==O:
        goal=e
    elif face==G:
        goal=h

    now=corner_permu[list_corner.index(goal)]
    now_spin=corner_ori[list_corner.index(goal)]
    if now==a:
        if now_spin==-1:
            return "F3U2F"
        elif now_spin==0:
            return "RUR2FRF3"
        elif now_spin==1:
            return "RU2R3"
    elif now==b:
        if now_spin==-1:
            return "F3UF"
        elif now_spin==0:
            return "F3U2F2R3F3R"
        elif now_spin==1:
            return "UR3FRF3"
    elif now==c:
        if now_spin==-1:
            return "FR3F3R"
        elif now_spin==0:
            return "U3F3U2F2R3F3R"
        elif now_spin==1:
            return "R3FRF3"
    elif now==d:
        if now_spin==-1:
            return "UF3U2F"
        elif now_spin==0:
            return "RU2R2FRF3"
        elif now_spin==1:
            return "RU3R3"
    elif now==e:
        if now_spin==-1:
            return "B3U3BRU3R3"
        elif now_spin==0:
            return "F3B3U2FB"
        elif now_spin==1:
            return "LUL3F3UF"
    elif now==f:
        if now_spin==-1:
            return "R3U2R2U3R3"
        elif now_spin==0:
            return "BU2B3RU3R3"
        elif now_spin==1:
            return "BF3UB3F"
    elif now==g:
        if now_spin==-1:
            return "RU3R2FRF3"
        elif now_spin==0:
            return ""
        elif now_spin==1:
            return "F3UF2R3F3R"
    elif now==h:
        if now_spin==-1:
            return "RL3U3R3L"
        elif now_spin==0:
            return "L3ULRU3R3"
        elif now_spin==1:
            return "FU2F2UF"
def solve_test():
    global formula
    formula_buf=solve_second_one()
    formula+=formula_buf
    for this,nex in zip(formula_buf,formula_buf[1:]):
        if nex=='2':
            rotate(this)
            rotate(this)
        elif nex=='3':
            rotate(this)
            rotate(this)
            rotate(this)
        else:
            rotate(this)
    if formula_buf:
        if not formula_buf[-1]==('2' or '3'):
            rotate(formula_buf[-1])
    rotate90()
    formula+="/"
    


def solve_second():
    for i in range(0,4):
        global formula
        formula_buf=solve_second_one()
        formula+=formula_buf
        for this,nex in zip(formula_buf,formula_buf[1:]):
            if nex=='2':
                rotate(this)
                rotate(this)
            elif nex=='3':
                rotate(this)
                rotate(this)
                rotate(this)
            else:
                rotate(this)
        if formula_buf:
            if not formula_buf[-1]==('2' or '3'):
                rotate(formula_buf[-1])
        rotate90()
        formula+="/"
        
def solve_second_one():
    face=center[0]


    if face==R:
        goal=7
    elif face==B:
        goal=6
    elif face==O:
        goal=5
    elif face==G:
        goal=8

    now=edge_permu[list_edge.index(goal)]
    now_spin=edge_ori[list_edge.index(goal)]
    if (goal==6 or goal== 8):
        if now_spin==0:
            now_spin=1
        else:
            now_spin=0



    if now==1:
        if now_spin==0:
            return "F3UFURU3R3"
        elif now_spin==1:
            return "U3RU3R3U3F3UF"
    if now==2:
        if now_spin==0:
            return "U3F3UFR3FRF3"###
        elif now_spin==1:
            return "U2RU3R3U3F3UF"
    elif now==3:
        if now_spin==0:
            return "U2F3UFURU3R3"
        elif now_spin==1:
            return "URU3R3U3F3UF"
    elif now==4:
        if now_spin==0:
            return "UF3UFURU3R3"
        elif now_spin==1:
            return "RU3R3U3F3UF"
    elif now==5:
        if now_spin==0:
            return "LU3L3U3B3UBU2F3UFURU3R3"
        elif now_spin==1:
            return "LU3L3U3B3UBURU3R3U3F3UF"
    elif now==6:
        if now_spin==0:
            return "BU3B3U3R3UR2U3R3U3F3UF"
        elif now_spin==1:
            return "BU3B3U3R3URUF3UFURU3R3"
    elif now==7:
        if now_spin==0:
            return ""
        elif now_spin==1:
            return "RU3R3UF3U2FU2F3UF"
    elif now==8:
        if now_spin==0:
            return "FU3F3U3L3ULU2RU3R3U3F3UF"
        elif now_spin==1:
            return "FU3F3U3L3ULU3F3UFURU3R3"

def solve_OLL():
        global formula
        formula_buf=OLL()
        formula+=formula_buf
        for this,nex in zip(formula_buf,formula_buf[1:]):
            if nex=='2':
                rotate(this)
                rotate(this)
            elif nex=='3':
                rotate(this)
                rotate(this)
                rotate(this)
            else:
                rotate(this)
        if formula_buf:
            if not formula_buf[-1]==('2' or '3'):
                rotate(formula_buf[-1])
        formula+="$"    

def OLL_rotater(spin):
    new_spin=[spin[3],spin[0],spin[1],spin[2],spin[7],spin[4],spin[5],spin[6]]
    return new_spin

def OLL():
    
    OLL_list=[[1,-1,0,0,0,0,0,0],
              [1,0,0,-1,0,0,0,0],
              [-1,0,1,0,0,0,0,0],
              [-1,0,-1,-1,0,0,0,0],
              [1,1,1,0,0,0,0,0],

              [1,-1,1,-1,0,0,0,0],
              [-1,-1,1,1,0,0,0,0],
              [0,1,-1,0,0,1,1,0],
              [0,1,-1,0,1,1,0,0],
              [0,1,0,-1,1,0,0,1],

              [-1,0,0,1,1,0,1,0],
              [1,0,0,-1,1,0,1,0],
              [-1,0,1,0,1,0,1,0],
              [0,-1,0,1,1,0,1,0],
              [0,0,-1,1,1,0,1,0],

              [0,1,-1,0,0,1,0,1],
              [1,0,-1,0,0,1,1,0],
              [0,1,0,-1,1,1,0,0],
              [1,0,0,-1,0,0,1,1],
              [0,1,0,-1,0,1,1,0],

              [1,-1,0,0,0,1,1,0],
              [0,0,1,-1,1,1,0,0],
              [0,0,-1,1,1,0,0,1],
              [1,0,0,-1,0,1,1,0],
              [1,0,0,-1,1,0,0,1],

              [0,0,0,0,0,1,1,0],
              [0,0,0,0,1,0,1,0],

              [-1,1,-1,1,1,1,1,1],
              [-1,-1,1,1,1,1,1,1],
              [1,1,0,1,1,1,1,1],
              [-1,0,-1,-1,1,1,1,1],
              [0,1,0,-1,1,1,1,1],

              [1,-1,0,0,1,1,1,1],
              [0,0,-1,1,1,1,1,1],
              [0,0,0,0,1,1,1,1],
              [-1,1,-1,1,1,0,1,0],
              [-1,1,-1,1,0,1,0,1],

              [1,1,-1,-1,1,0,1,0],
              [1,1,-1,-1,0,1,0,1],
              [1,-1,1,-1,0,1,1,0],
              [1,-1,1,-1,1,1,0,0],
              [1,1,-1,-1,1,1,0,0],

              [1,1,-1,-1,0,1,1,0],
              [-1,-1,1,1,0,1,1,0],
              [-1,-1,1,1,1,1,0,0],
              [1,1,1,0,0,1,1,0],
              [0,-1,-1,-1,1,1,0,0],

              [0,-1,-1,-1,0,0,1,1],
              [1,1,1,0,1,0,0,1],
              [-1,-1,0,-1,0,1,1,0],
              [1,0,1,1,1,1,0,0],
              [1,1,0,1,1,0,0,1],

              [-1,0,-1,-1,0,0,1,1],
              [1,1,1,0,1,0,1,0],
              [-1,-1,0,-1,1,0,1,0],
              [-1,0,-1,-1,1,0,1,0],
              [0,1,1,1,1,0,1,0]]
              
    OLL_formula=["R3U2RFU3R3U3RUF3",
                 "LFR3F3L3FRF3",
                 "F3LFR3F3L3FR",
                 "RU2R3U3RU3R3",
                 "RUR3URU2R3",

                 "RU2R3U3RUR3U3RU3R3",
                 "RU2R2U3R2U3R2U2R",
                 "FURU3R3F3",
                 "B3U3R3URB",
                 "RU2R2FRF3RU2R3",
                 
                 "FRUR3U3F3",
                 "RUR3U3R3FRF3",
                 "RB3R3U3RUBU3R3",
                 "R3FRUR3U3F3UR",
                 "R3U3RUFRB3R3F3B",
                 
                 "R3U3R3FRF3UR",
                 "RUR3URU3R3U3R3FRF3",
                 "R3U3RU3R3URURB3R3B",
                 "R3U3FURU3R3F3R",
                 "FRU3R3U3RUR3F3",
                 

                 "RUR3URU2R3FRUR3U3F3",
                 "R3U3RUFRUR3U3R3URU3F3",
                 "R2UR3B3RU3R2URBR3",
                 "RUR3U3RU3R3F3U3FRUR3",
                 "RUB3U3R3URBR3",

                 "LFR3F3L3RURU3R3",
                 "RUR3U3LR3FRF3L3",
                 
                 "RU2R2FRF3U2R3FRF3",
                 "FRUR3U3F3BULU3L3B3",
                 "BULU3L3B3U3FRUR3U3F3",
                 "BULU3L3B3RBUB3U3R3",
                 "FUR3U3F3UFR2UR3U3F3",

                 "FRUR3UF3U2F3LFL3",
                 "L3RBRBR3B3LR2FRF3",
                 "L3RBRBR3B3L2R2FRF3L3",
                 "FRUR3U3RF3LFR3F3L3",
                 "RU2R2U3RU3R3U2FRF3",

                 "FURU3R3URU3R3F3",
                 "R3U3RU3R3UF3UFR",
                 "LF2R3F3RFR3F3RF3L3",
                 "L3B2RBR3B3RBR3BL",
                 "RB3R2FR2BR2F3R",
                 
                 "R3FR2B3R2F3R2BR3",
                 "FRUR3U3RUR3U3F3",
                 "B3R3U3RUR3U3RUB",
                 "LFR3FRF2L3",
                 "L3B3RB3R3B2L",
                 
                 "LR2F3RF3R3F2RF3RL3",
                 "L3R2BR3BRB2R3BR3L",
                 "R3U3RFR3F3UFRF3",
                 "RUR3UR3FRF3RU2R3",
                 "L3B2RBR3BL",

                 "LF2R3F3RF3L3",
                 "LF3L3U3LFL3F3UF",
                 "R3FRUR3F3RFU3F3",
                 "LFL3RUR3U3LF3L3",
                 "R3F3RL3U3LUR3FR"]
    num_u=0
    spin=[corner_ori[corner_permu.index('a')],corner_ori[corner_permu.index('b')],corner_ori[corner_permu.index('c')],corner_ori[corner_permu.index('d')],edge_ori[edge_permu.index(1)],edge_ori[edge_permu.index(2)],edge_ori[edge_permu.index(3)],edge_ori[edge_permu.index(4)]]
    for rotation in range(0,4):
        
        for i in range(0,len(OLL_list)):
            if spin==OLL_list[i]:
                return 'U'*num_u+OLL_formula[i]
        spin=OLL_rotater(spin)
        num_u+=1
    return ''

    
def solve_PLL():
        global formula
        formula_buf=PLL()
        formula+=formula_buf
        for this,nex in zip(formula_buf,formula_buf[1:]):
            if nex=='2':
                rotate(this)
                rotate(this)
            elif nex=='3':
                rotate(this)
                rotate(this)
                rotate(this)
            else:
                rotate(this)
        if formula_buf:
            if not formula_buf[-1]==('2' or '3'):
                rotate(formula_buf[-1])
        formula+="$"    

def PLL_rotate90(permu):
    new_corner=permu[:3]
    new_corner.insert(0,permu[3])
    new_edge=permu[4:7]
    new_edge.insert(0,permu[7])
    new_permu=new_corner+new_edge
    for i in range(0,len(new_permu)):
        if new_permu[i]==a:
            new_permu[i]=b
        elif new_permu[i]==b:
            new_permu[i]=c      
        elif new_permu[i]==c:
            new_permu[i]=d      
        elif new_permu[i]==d:
            new_permu[i]=a      
        elif new_permu[i]==1:
            new_permu[i]=2      
        elif new_permu[i]==2:
            new_permu[i]=3
        elif new_permu[i]==3:
            new_permu[i]=4      
        elif new_permu[i]==4:
            new_permu[i]=1      
    return new_permu
        

def PLL_rotater(permu):
    new_permu=[permu[3],permu[0],permu[1],permu[2],permu[7],permu[4],permu[5],permu[6]]
    return new_permu

def PLL():

    PLL_list=[[c,b,d,a,1,2,3,4],
              [a,d,b,c,1,2,3,4],
              [b,a,d,c,1,2,3,4],
              [a,b,c,d,2,4,3,1],
              [a,b,c,d,4,1,3,2],
              [a,b,c,d,2,1,4,3],
              [a,b,c,d,3,4,1,2],
              [a,c,b,d,1,3,2,4],
              [a,c,b,d,2,1,3,4],
              [b,a,c,d,1,3,2,4],
              [b,a,c,d,1,2,4,3],
              [a,c,b,d,1,4,3,2],
              [a,c,b,d,3,2,1,4],
              [b,c,a,d,4,1,3,2],
              [c,a,b,d,2,4,3,1],
              [d,a,c,b,2,4,3,1],
              [b,d,c,a,4,1,3,2],
              [a,d,c,b,1,3,2,4],
              [c,b,a,d,4,2,3,1],
              [c,b,a,d,1,4,3,2],
              [a,d,c,b,1,4,3,2],
              [a,b,c,d,1,2,3,4]]

    PLL_formula=["L3BL3F2LB3L3F2L2",
                 "RB3RF2R3BRF2R2",
                 "FR3F3LFRF3L3FRF3LFR3F3L3",
                 "L2ULUL3U3L3U3L3UL3",
                 "R2U3R3U3RURURU3R",
                 "R3U3RU3RURU3R3URUR2U3R3U2",
                 "L2R2DL2R2U2L2R2DL2R2",
                 "RU2R3U3RU2L3UR3U3L",
                 "R3U2RUR3U2LU3RUL3",
                 "R3U2RU2R3FRUR3U3R3F3R2U3",
                 "LU2L3U2LF3L3U3LULFL2U",
                 "RUR3U3R3FR2U3R3U3RUR3F3",
                 "U3R3URU3R2F3U3FURFR3F3R2",
                 "FUF3L2D3BU3B3UB3DL2",
                 "L2D3BU3BUB3DL2FU3F3",
                 "F3U3FR2DB3UBU3BD3R2",
                 "R2DB3UB3U3BD3R2F3UF",
                 "L3URU3LUL3UR3U3LU2RU2R3",
                 "FRU3R3U3RUR3F3RUR3U3R3FRF3",
                 "L3UR3U2LU3RL3UR3U2LU3RU",
                 "LU3RU2L3UR3LU3RU2L3UR3U3",
                 ""]
    permu=[list_corner[corner_permu.index('a')],list_corner[corner_permu.index('b')],list_corner[corner_permu.index('c')],list_corner[corner_permu.index('d')],list_edge[edge_permu.index(1)],list_edge[edge_permu.index(2)],list_edge[edge_permu.index(3)],list_edge[edge_permu.index(4)]]
    for rotation in range(0,4):
        for rot90 in range(0,4):
           

            for i in range(0,len(PLL_list)):
                if permu==PLL_list[i]:
                    return 'U'*rotation+'U'*rot90+PLL_formula[i]+'U3'*rot90

            permu=PLL_rotate90(permu)
   
        permu=PLL_rotater(permu)
    




def edge_ori_change(edge_at,ori):
    if ori==1:
        if edge_ori[edge_at]==1:
            edge_ori[edge_at]=0
        elif edge_ori[edge_at]==0:
            edge_ori[edge_at]=1

def change_edge(one,two,three,four,ori_one,ori_two,ori_three,ori_four):

    lo_one,lo_two,lo_three,lo_four=edge_permu.index(one),edge_permu.index(two),edge_permu.index(three),edge_permu.index(four)
 
    for i,j in zip([lo_one,lo_two,lo_three,lo_four],[ori_one,ori_two,ori_three,ori_four]):
        edge_ori_change(i,j)
    edge_permu[lo_one],edge_permu[lo_two],edge_permu[lo_three],edge_permu[lo_four]=two,three,four,one   

    

def corner_ori_change(corner_at,ori):
    corner_ori[corner_at]+=ori
    if corner_ori[corner_at]==2:
        corner_ori[corner_at]=-1
    elif corner_ori[corner_at]==-2:
        corner_ori[corner_at]=1


def change_corner(one,two,three,four,ori_one,ori_two,ori_three,ori_four):
    
    lo_one,lo_two,lo_three,lo_four=corner_permu.index(one),corner_permu.index(two),corner_permu.index(three),corner_permu.index(four)
    for i,j in zip([lo_one,lo_two,lo_three,lo_four],[ori_one,ori_two,ori_three,ori_four]):
        corner_ori_change(i,j)


    corner_permu[lo_one],corner_permu[lo_two],corner_permu[lo_three],corner_permu[lo_four]=two,three,four,one



def rotate(rotation):
    if rotation=='U':
        change_corner(a,b,c,d,0,0,0,0)
        change_edge(1,2,3,4,0,0,0,0)
        
    elif rotation=='D':
        change_corner(e,h,g,f,0,0,0,0)
        change_edge(9,12,11,10,0,0,0,0)
      
    elif rotation=='F':
        change_corner(c,g,h,d,1,-1,1,-1)
        change_edge(7,11,8,3,1,1,1,1)
      
    elif rotation=='B':
        change_corner(a,e,f,b,1,-1,1,-1)
        change_edge(1,5,9,6,1,1,1,1)
      
    elif rotation=='R':
        change_corner(b,f,g,c,1,-1,1,-1)
        change_edge(2,6,10,7,0,0,0,0)
      
    elif rotation=='L':
        change_corner(a,d,h,e,-1,1,-1,1)
        change_edge(4,8,12,5,0,0,0,0)
      


        
def rotate90():

    change_corner(a,b,c,d,0,0,0,0)
    change_edge(1,2,3,4,0,0,0,0)
    change_corner(f,g,h,e,0,0,0,0)
    change_edge(10,11,12,9,0,0,0,0)
    change_edge(5,6,7,8,0,0,0,0)
   
        

    for edges in list_edge[0:4]+list_edge[8:12]:
        if (edge_permu[edges-1]==5 or edge_permu[edges-1]==6 or edge_permu[edges-1]==7 or edge_permu[edges-1]==8):
            if edge_ori[list_edge.index(edges)]==1:
                edge_ori[list_edge.index(edges)]=0
            else :
                edge_ori[list_edge.index(edges)]=1
    
    for edges in list_edge[4:8]:
        if (edge_permu[edges-1]==5 or edge_permu[edges-1]==6 or edge_permu[edges-1]==7 or edge_permu[edges-1]==8):
            if edge_ori[list_edge.index(edges)]==1:
                edge_ori[list_edge.index(edges)]=0
            else :
                edge_ori[list_edge.index(edges)]=1

            


    center.append(center.pop(0))

def shuffle(n):
    for i in range(0,n):
        chooser=random.randrange(1,7)
        if chooser==1:
            rotate('U')
        elif chooser==2:
            rotate('D')
        elif chooser==3:
            rotate('F')
        elif chooser==4:
            rotate('B')
        elif chooser==5:
            rotate('R')
        elif chooser==6:
            rotate('L')




def show():
    print corner_permu
    print corner_ori
    print edge_permu
    print edge_ori


def test():
    base_corner_permu=[a,b,c,d,e,f,g,h]
    base_corner_ori  =[0,0,0,0,0,0,0,0]
    base_edge_permu=[1,2,3,4,5,6,7,8,9,10,11,12]
    base_edge_ori  =[0,0,0,0,0,0,0,0,0,0 ,0 ,0 ]
    success=0
    fail=0
    n=10000
    for i in range(0,n):
        global formula
        formula=""
        shuffle(20)
        cross_solve()
        solve_first()
        solve_second()        
        solve_OLL()
        solve_PLL()
        if not (corner_permu==base_corner_permu and corner_ori==base_corner_ori and edge_permu==base_edge_permu and edge_ori==base_edge_ori):
            fail+=1
 
    print "success=%d\n"%(n-fail)
    print "fail=%d\n"%(fail)


def cube_form():
    global corner_permu,corner_ori,edge_permu,edge_ori
    cube_array=create_cube()    
    corner_permu=cube_array[0]
    corner_ori=cube_array[1]
    edge_permu=cube_array[2]
    edge_ori=cube_array[3]
    shuffle(20)
    cube_str=''
    cube_str=cube_str.join(corner_permu)
    for atom in corner_ori:
        if atom == -1:
            cube_str+='t'
        elif atom ==0:
            cube_str+='0'
        elif atom == 1:
            cube_str+='1'
    for atom in edge_permu:
        if atom == 1:
            cube_str+='1'
        elif atom ==2:
            cube_str+='2'
        elif atom == 3:
            cube_str+='3'
        elif atom ==4:
            cube_str+='4'
        elif atom ==5:
            cube_str+='5'
        elif atom ==6:
            cube_str+='6'
        elif atom == 7:
            cube_str+='7'
        elif atom ==8:
            cube_str+='8'
        elif atom == 9:
            cube_str+='9'
        elif atom ==10:
            cube_str+='x'
        elif atom ==11:
            cube_str+='y'
        elif atom ==12:
            cube_str+='z'
    for atom in edge_ori:
        if atom==0:
            cube_str+='0'
        elif atom==1:
            cube_str+='1'
    return cube_str

def solution():
    cross_solve()
    solve_first()
    solve_second()
    solve_OLL()
    solve_PLL()
    arr_formula=''
    turn_count=0
    U_count=0
   
    for i in range(0,len(formula)):
        if formula[i]=='/':
            turn_count+=1
#            print 1
            if turn_count>=4:
                turn_count-=4
#                print 2
        elif formula[i]=='U':
            U_count=1
            while(formula[i+U_count]=='U'):
                U_count+=1

            if U_count>=4:
                U_count-=4
            if U_count==1:
                arr_formula+='U'
            else:
                arr_formula+='U{0}'.format(U_count)


        elif formula[i]=='D':
            arr_formula+='D'

#            print 5
        elif formula[i]=='3':
            arr_formula+='3'
#            print 6
        elif formula[i]=='2':
            arr_formula+='2'
#            print 7
        elif (formula[i]=='F' or formula[i]=='D' or formula[i]=='B' or formula[i]=='R' or formula[i]=='L'):
            a=arrange(formula[i],turn_count)
            arr_formula+=a
#            print 8
    return arr_formula

def arrange(turn, turn_count):
    index=0
    turn_array=['F','R','B','L','F','R','B','L','F','R','B','L']
    if turn=='F':
        index=0
    elif turn=='R':
        index=1
    elif turn=='B':
        index=2
    elif turn=='L':
        index=3
    index+=turn_count
  
    return turn_array[index]
    
def send_cube():
    a=cube_form()
    b=solution()
    return a+b
