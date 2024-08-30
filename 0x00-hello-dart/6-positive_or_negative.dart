void main(List<String> args) {
  int n = int.parse(args[0]);

  String result = (n == 0)
      ? '$n is zero'
      : (n > 0)
          ? '$n is positive'
          : '$n is negative';
  print(result);
}
