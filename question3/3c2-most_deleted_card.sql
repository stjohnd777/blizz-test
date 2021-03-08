# Most Deleted Card

select deck.card_id, count(deck.card_id) as deleted_card_count
   from player_deck as deck
   where deck.deleted = 1
   GROUP by deck.card_id
   order by deleted_card_count DESC  LIMIT 1;


# For the average delete time
# Knowing the card id above
select  avg(time_deleted-created) from player_deck where card_id = 3005