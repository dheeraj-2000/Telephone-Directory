# -*- coding: utf-8 -*-
"""
Created on Sat Dec  2 14:57:25 2017

@author: SATYAM COMPUTERS
"""


def modification():
    from database import telephone as pl
    item=int(input(' Enter the phone number :'))
    if item not in pl:
        print('\n Number does not exist ')
    else:
        print(' Existing Number :\n name of the person : {}\n gender of person  : {}\n age of the person : {}'.format(pl[item][0].ljust(20),pl[item][1],pl[item][2]))
        pl[item][0]=(input('Enter the new  name :'))
        pl[item][1]=(input('Enter gender of person :'))
        pl[item][2]=int(input('Enter age of person :'))
        print('Modified details are:\n', pl[item])