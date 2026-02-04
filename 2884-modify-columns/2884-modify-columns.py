import pandas as pd

def multiply(x):
    return x*2

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees["salary"]= employees["salary"].apply(multiply)
    return employees