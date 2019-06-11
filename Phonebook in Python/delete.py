# -*- coding: utf-8 -*-
"""
Created on Sat Dec  2 15:12:35 2017

@author: SATYAM COMPUTERS
"""

def delete_items():
    from database import telephone as pl
    while 1:
        value=int(input('Enter telephone number:'))
        if value in pl.keys():
            print( 'Name of the person : {}\ngender of person :  {}\nage of the person :  {}'.format(pl[value][0],pl[value][1],pl[value][2]))
            ch=input(' Confirm delete? (yes/no): ')
            if ch=='yes':
                del pl[value]     
            else: 
                print(' Number not deleted')
        else:
            print('\n Number does not exist')
        choice=input(' Do you want to delete more items? (yes/no): ')
        if choice!='yes':
            break