#Python script to pull google sheets data so that user is able to easily run script

import pandas as pd

def get_sheetAsCSV(Doc_id, Sheet_id):
    return f'https://docs.google.com/spreadsheets/d/{Doc_id}/export?format=csv&gid={Sheet_id}'

def main():
    doc_id = '1bGVIi_2x536afZ2NdsJ6Qly4Em5w8TM7zw_tUSyDfUI'
    sheet_id = '642895214'

    URL = get_sheetAsCSV(doc_id, sheet_id)

    #Pull the excel sheet from drive

    data_frame = pd.read_csv(URL)
    #Store it as local file called "Data.csv"
    data_frame.to_csv("Data.csv")

if(__name__ == '__main__'):
    main()