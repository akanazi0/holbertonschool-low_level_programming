#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (Success), NULL otherwise
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *new_name, *new_owner;
	int name_len = 0, owner_len = 0, i;

	if (name == NULL || owner == NULL)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	while (name[name_len] != '\0')
		name_len++;

	new_name = malloc(sizeof(char) * (name_len + 1));
	if (new_name == NULL)
	{
		free(dog);
		return (NULL);
	}
	for (i = 0; i < name_len; i++)
		new_name[i] = name[i];
	new_name[i] = '\0';

	while (owner[owner_len] != '\0')
		owner_len++;

	new_owner = malloc(sizeof(char) * (owner_len + 1));
	if (new_owner == NULL)
	{
		free(new_name);
		free(dog);
		return (NULL);
	}
	for (i = 0; i < owner_len; i++)
		new_owner[i] = owner[i];
	new_owner[i] = '\0';

	dog->name = new_name;
	dog->age = age;
	dog->owner = new_owner;

	return (dog);
}
