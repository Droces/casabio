<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPPlus;

use PHPExiftool\Driver\AbstractTag;

class CopyrightStatus extends AbstractTag
{

    protected $Id = 'CopyrightStatus';

    protected $Name = 'CopyrightStatus';

    protected $FullName = 'XMP::plus';

    protected $GroupName = 'XMP-plus';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-plus';

    protected $g2 = 'Author';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Copyright Status';

    protected $Values = array(
        'CS-PRO' => array(
            'Id' => 'CS-PRO',
            'Label' => 'Protected',
        ),
        'CS-PUB' => array(
            'Id' => 'CS-PUB',
            'Label' => 'Public Domain',
        ),
        'CS-UNK' => array(
            'Id' => 'CS-UNK',
            'Label' => 'Unknown',
        ),
    );

}