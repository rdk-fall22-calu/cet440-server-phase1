build: update-repo
	gcc -std=c99 src/*.h src/*.c -o build/server

update-repo:
	git pull