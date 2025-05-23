pipeline {
    agent any

    stages {
        stage('Tools Information') {
            steps {
                sh "g++ --version"
                sh "make --version"
                sh "cmake --version"
                sh "ls -al"
            }
        }

        stage("Build") {
            steps {
                sh '''
                conan install . --output-folder=. --build=missing

                cd build
                cmake .. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=`pwd`/Release/generators/conan_toolchain.cmake -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release
                source ./Release/generators/conanbuild.sh
                cmake --build .
                source ./Release/generators/deactivate_conanbuild.sh
                '''
            }
        }

        stage("SAST") {
            steps {
                sh '''
                    #cppcheck --enable=all --inconclusive --library=posix include/ sources/ test/ bin/
                '''
            }
        }

        stage("Tests") {
            steps {
                #echo "Tests"
                #sh "bin/unit_tests"
                source ./Release/generators/deactivate_conanbuild.sh
                ctest --test-dir test
                source ./Release/generators/deactivate_conanbuild.sh
            }
        }
    }
}
