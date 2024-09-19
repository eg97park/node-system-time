{
  'targets': [
    {
      'target_name': 'node-system-time',
      'sources': [ 'src/system-time.c' ],
      "include_dirs": [ "<!@(node -p \"require('node-addon-api').include\")" ],
      "dependencies": [ "<!@(node -p \"require('node-addon-api').gyp\")" ]
    }
  ]
}