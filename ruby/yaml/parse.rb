=begin
---
receipt:     Oz-Ware Purchase Invoice
date:        2012-08-06
customer:
    given:   Dorothy
    family:  Gale

items:
    - part_no:   A4786
      descrip:   Water Bucket (Filled)
      price:     1.47
      quantity:  4

    - part_no:   E1628
      descrip:   High Heeled "Ruby" Slippers
      size:      8
      price:     100.27
      quantity:  1

bill-to:  &id001
    street: |
            123 Tornado Alley
            Suite 16
    city:   East Centerville
    state:  KS

ship-to:  *id001

specialDelivery:  >
    Follow the Yellow Brick
    Road to the Emerald City.
    Pay no attention to the
    man behind the curtain.
...
=end

require 'yaml'

text = YAML::load_file('test.yml');
raise unless text.class==Hash
#puts text

raise unless text["receipt"]=="Oz-Ware Purchase Invoice"
#raise unless text["date"]=="2012-08-06"
raise unless text["customer"]["given"]=="Dorothy"
raise unless text["customer"]["family"]=="Gale"
raise unless text["items"][0]["part_no"]=="A4786"
raise unless text["items"][0]["descrip"]=="Water Bucket (Filled)"
raise unless text["items"][0]["price"]==1.47
raise unless text["items"][0]["quantity"]==4
raise unless text["items"][1]["part_no"]=="E1628"
raise unless text["items"][1]["descrip"]=="High Heeled \"Ruby\" Slippers"
raise unless text["items"][1]["size"]==8
raise unless text["items"][1]["price"]==100.27
raise unless text["items"][1]["quantity"]==1
raise unless text["bill-to"]["street"]=="123 Tornado Alley\nSuite 16\n"
raise unless text["bill-to"]["city"]=="East Centerville"
raise unless text["bill-to"]["state"]=="KS"
raise unless text["ship-to"]["street"]=="123 Tornado Alley\nSuite 16\n"
raise unless text["ship-to"]["city"]=="East Centerville"
raise unless text["ship-to"]["state"]=="KS"
raise unless text["specialDelivery"]=="Follow the Yellow Brick Road to the Emerald City. Pay no attention to the man behind the curtain.\n"
