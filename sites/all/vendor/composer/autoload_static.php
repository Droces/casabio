<?php

// autoload_static.php @generated by Composer

namespace Composer\Autoload;

class ComposerStaticInitComposerManager
{
    public static $prefixLengthsPsr4 = array (
        'P' => 
        array (
            'Psr\\Log\\' => 8,
        ),
        'M' => 
        array (
            'Monolog\\' => 8,
        ),
        'D' => 
        array (
            'Drupal\\service_container\\Tests\\' => 31,
            'Drupal\\service_container\\' => 25,
        ),
    );

    public static $prefixDirsPsr4 = array (
        'Psr\\Log\\' => 
        array (
            0 => __DIR__ . '/..' . '/psr/log/Psr/Log',
        ),
        'Monolog\\' => 
        array (
            0 => __DIR__ . '/..' . '/monolog/monolog/src/Monolog',
        ),
        'Drupal\\service_container\\Tests\\' => 
        array (
            0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/tests/src',
        ),
        'Drupal\\service_container\\' => 
        array (
            0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/src',
        ),
    );

    public static $prefixesPsr0 = array (
        'S' => 
        array (
            'Symfony\\Component\\Process\\' => 
            array (
                0 => __DIR__ . '/..' . '/symfony/process',
            ),
            'Symfony\\Component\\DependencyInjection' => 
            array (
                0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/lib',
            ),
            'ServiceContainer' => 
            array (
                0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/lib',
            ),
        ),
        'P' => 
        array (
            'Psr' => 
            array (
                0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/lib',
            ),
            'PHPExiftool' => 
            array (
                0 => __DIR__ . '/..' . '/phpexiftool/phpexiftool/lib',
            ),
        ),
        'D' => 
        array (
            'Drupal\\Core\\' => 
            array (
                0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/lib',
            ),
            'Drupal\\Component\\' => 
            array (
                0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/lib',
            ),
            'Drupal' => 
            array (
                0 => __DIR__ . '/../../..'.'/default/files/composer' . '/../../../all/modules/service_container/lib',
            ),
            'Doctrine\\Common' => 
            array (
                0 => __DIR__ . '/..' . '/doctrine/common/lib',
            ),
        ),
    );

    public static function getInitializer(ClassLoader $loader)
    {
        return \Closure::bind(function () use ($loader) {
            $loader->prefixLengthsPsr4 = ComposerStaticInitComposerManager::$prefixLengthsPsr4;
            $loader->prefixDirsPsr4 = ComposerStaticInitComposerManager::$prefixDirsPsr4;
            $loader->prefixesPsr0 = ComposerStaticInitComposerManager::$prefixesPsr0;

        }, null, ClassLoader::class);
    }
}
