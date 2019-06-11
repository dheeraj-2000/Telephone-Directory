# -*- coding: utf-8 -*-
"""
Created on Sat Dec  2 14:38:35 2017

@author: SATYAM COMPUTERS
"""


from database import telephone as items
def add_items():
    code=int(input("\nEnter phone number : "))
    if code not in items.keys():
        name=input("Enter new name : ")
        gender=input("Enter gender of person : ")
        age=int(input("Enter age of person  : "))
        items.update({code:[name,gender,age]})
    else:
        print("Number already exists")
