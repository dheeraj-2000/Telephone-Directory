# -*- coding: utf-8 -*-
"""
Created on Sat Dec  2 14:23:42 2017

@author: SATYAM COMPUTERS
"""


from modify import modification as m
from add import add_items as a
from delete import delete_items as d
from disp import display as l 

while 1:
    print('\n\n\n     Telehone directory')
    print('\n\t MENU')
    print('\n 1. Display Number list \n 2. Add Nem numbers \n 3. Modify person details \n 4. Delete number with their details \n 5. Exit')
    ch=int(input(' \n Enter your choice : '))
    if ch==1:
        l()
    elif ch==2:
        a()
    elif ch==3:
        m()
    elif ch==4:
        d()
    elif ch==5:
        break
    else:
        print(' \n wrong choice!!!!!!')