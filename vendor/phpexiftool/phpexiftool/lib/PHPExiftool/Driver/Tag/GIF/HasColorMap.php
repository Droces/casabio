<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\GIF;

use PHPExiftool\Driver\AbstractTag;

class HasColorMap extends AbstractTag
{

    protected $Id = '4.1';

    protected $Name = 'HasColorMap';

    protected $FullName = 'GIF::Screen';

    protected $GroupName = 'GIF';

    protected $g0 = 'GIF';

    protected $g1 = 'GIF';

    protected $g2 = 'Image';

    protected $Type = 'int8u';

    protected $Writable = false;

    protected $Description = 'Has Color Map';

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'No',
        ),
        128 => array(
            'Id' => 128,
            'Label' => 'Yes',
        ),
    );

}
