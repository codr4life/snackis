''Welcome to Snackis'' say

'peers
['name db.new-str-column]
['key db.new-bin-column]
db.new-table
let: peer-table

@db @peer-table db.create

while: (
  yield!
  gui.refresh-console
  gui.run
)