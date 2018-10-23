'peers
['name db.new-str-column]
['key db.new-bin-column]
db.new-table
let: peer-table

@db @peer-table await: db.create

while:, await: gui.run