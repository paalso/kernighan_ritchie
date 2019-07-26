from sys import argv, exit


def load_keywords(filename):
    keywords_file = open(filename, 'r')
    keywords = []
    for line in keywords_file:
        keywords.append(line.rstrip('\n'))
    keywords_file.close()
    return keywords


def main():
    # keywords = load_keywords(argv[1])
    keywords = load_keywords("keywords_list.txt")
    for word in keywords:
        print('{0}{1}{0}, 0,'.format('"', word))


if __name__ == "__main__":
    main()
