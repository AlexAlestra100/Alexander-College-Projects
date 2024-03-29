import sqlite3
import csv

conn = sqlite3.connect('forTaxPurposes.db')

c = conn.cursor()

c.execute('''CREATE TABLE IF NOT EXISTS stocks(date text, trans text, symbol text, qty real, price real)''')

c.execute("INSERT INTO stocks VALUES ('2006-01-05','BUY','RHAT',100,35.14)")

conn.commit()

t = ('RHAT',)
c.execute('SELECT * FROM stocks WHERE symbol=?', t)
print(c.fetchone())

purchases = [('2006-03-28', 'BUY', 'IBM', 1000, 45.00),
             ('2006-04-05', 'BUY', 'MSFT', 1000, 72.00),
             ('2006-04-06', 'SELL', 'IBM', 500, 53.00),
            ]
c.executemany('INSERT INTO stocks VALUES (?,?,?,?,?)', purchases)

for row in c.execute('SELECT * FROM stocks ORDER BY price'):
    print(row)

conn.commit()

conn.close()

conn = sqlite3.connect('forTaxPurposes.db')

c = conn.cursor()
c.execute('SELECT * FROM stocks ORDER BY price')
rows = c.fetchall()

with open('stocks.csv', 'w') as f:
    writer = csv.writer(f)
    for r in rows:
        writer.writerow(r)

    f.close()
