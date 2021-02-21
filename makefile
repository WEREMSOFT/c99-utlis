TYPE:=GameObject
TYPE_UPPERCASE:=GAME_OBJECT
TYPEDEF_FILENAME:=game_object.h
generate_array:
	sed 's/__TYPE__/$(TYPE)/g' array_template._h_ > game_object_array.h
	sed -i 's/__TYPE_UPPERCASE__/$(TYPE_UPPERCASE)/g' game_object_array.h
	sed -i 's/__TYPEDEF_FILE_NAME__/$(TYPEDEF_FILENAME)/g' game_object_array.h
	