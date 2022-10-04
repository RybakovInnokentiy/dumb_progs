import json
import os
from symbol import parameters 

parametres_dict = ["date", "card", "account", "account_valid_to", "client", "first_name", "last_name", "patronymic", 
                   "date_of_birth", "passport", "passport_valid_to", "phone", "oper_type", "amount",
                   "oper_result", "terminal", "terminal_type", "city", "address"]
data_trans_set = {}
for i in range(len(parametres_dict)):
    data_trans_set[parametres_dict[i]] = []

with open("transactions.json", "r") as json_read:
    json_data = json.load(json_read)

transaction_keys = json_data["transactions"].keys()

for tran_key in transaction_keys:
    messages_set = json_data["transactions"][tran_key]
    for parameter in messages_set.keys():
        data_trans_set[parameter] += [messages_set[parameter]]

for parameter in data_trans_set.keys():
    print("\n", parameter, " : \n")
    print(data_trans_set[parameter])

  