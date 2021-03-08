# Average Players Deck Size

select avg(dt.active_cards) as average_deck_size from
   (
       select deck.player_id, count(deck.player_id) as active_cards
       from blizzard.player_deck as deck,
            blizzard.card_definitions_simple as def
       where deck.deleted = 0
         and def.id = deck.card_id
         and deck.player_id in (select player_id as p from player_deck)
       group by deck.player_id
   ) as dt