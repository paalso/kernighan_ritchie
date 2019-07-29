def file_search(folder, filename):
    for item in folder:
        if isinstance(item, str):
            # print(item + " == " + filename + " : " + item == filename)
            print(f"{item} == {filename} : {item == filename}")
            if item == filename:
                return True
        else:
            print(item)
            file_search(item, filename)
    return False


# result = file_search(['C:', 'backup.log', 'ideas.txt'], 'ideas.txt')
# print(result)

# result = file_search([ 'D:', ['recycle bin'], ['tmp', ['old'], ['new folder1', 'asd.txt', 'asd.bak', 'find.me.bak' ] ], 'hey.py'], 'find.me')
# print(result)

result = file_search([ '/home', ['user1'], ['user2', ['my pictures'], ['desktop', 'not this', 'and not this', ['new folder', 'hereiam.py' ] ] ], 'work.ovpn', 'prometheus.7z', ['user3', ['temp'], ], 'hey.py'], 'hereiam.py')
print(result)